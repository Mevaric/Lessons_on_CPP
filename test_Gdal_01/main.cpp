#include <iostream>
//#include <gdal.h>
//#include <gdal_priv.h>
//#include <drv>
#include <ogrsf_frmts.h>
#include <ogr_feature.h>
int main() {
	//setlocale(LC_ALL, "Russian");
	const char *input = "C:/Dev-src/gis/Новая папка/Untitled.TAB";
	//const char *output = "C:/Dev-src/gis/poligon/poligon line text point1.tif";
	CPLSetConfigOption("GDAL_FILENAME_IS_UTF8", "NO");
	GDALAllRegister();
	GDALDataset *pOldDS;// , *pNewDS;
	//GDALDriver *pDriverMap, *pDriverTiff;
	//pDriverMap = GetGDALDriverManager()->GetDriverByName("MapInfo File");
	//pDriverTiff = GetGDALDriverManager()->GetDriverByName("GTiff");
	//
	//pOldDS = (GDALDataset*)GDALOpen(input, GA_ReadOnly);
	//
	pOldDS = (GDALDataset*)GDALOpenEx(input, GDAL_OF_ALL , NULL, NULL, NULL);
	if (pOldDS == NULL) {
		std::cout << "Open is failed" << std::endl;
		exit(1);
	}
	//pNewDS = pDriverTiff->CreateCopy(output, pOldDS, FALSE, NULL, NULL, NULL);
	OGRLayer *pLayer;
	int iLayer = pOldDS->GetLayerCount();
	pLayer = pOldDS->GetLayer(0);
	OGRFeature *pFeature;
	pLayer->ResetReading();
	while ((pFeature = pLayer->GetNextFeature())!=NULL)
	{
		OGRFeatureDefn *pFDefn = pLayer->GetLayerDefn();
		int iField;
		for (iField = 0; iField < pFDefn->GetFieldCount(); iField++)
		{
			OGRFieldDefn* pFieldDefn = pFDefn ->GetFieldDefn(iField);

			if (pFieldDefn->GetType() == OFTInteger)
				printf(CPL_ENC_LOCALE "%d", pFeature->GetFieldAsInteger(iField));
			else if (pFieldDefn->GetType() == OFTInteger64)
				printf(CPL_FRMT_GIB ",", pFeature->GetFieldAsInteger64(iField));
			else if (pFieldDefn->GetType() == OFTReal)
				printf("%.3f", pFeature->GetFieldAsDouble(iField));
			else if (pFieldDefn->GetType() == OFTString)
				printf(CPL_ENC_LOCALE "%s", pFeature->GetFieldAsString(iField));
			else
				printf(CPL_ENC_LOCALE "%s", pFeature->GetFieldAsString(iField));
		}
		OGRGeometry *pGeometry;
		pGeometry = pFeature->GetGeometryRef();
		if (pGeometry != NULL && wkbFlatten(pGeometry -> getGeometryType()) == wkbPoint)
		{
			OGRPoint *pPoint = (OGRPoint*)pGeometry;
			
			printf("%.3f, %3.f\n", pPoint->getX(), pPoint->getY());
	
		}
		else
		{
			printf("no point geometry\n");
		}
	
		OGRFeature::DestroyFeature(pFeature);
	}
	GDALClose(pOldDS);
	std::cin.get();
	return 0;
}