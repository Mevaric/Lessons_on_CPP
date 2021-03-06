// SimpleFTP_ConsUp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <WinInet.h>

#pragma comment(lib, "wininet")


int main()
{
	HINTERNET hInternet;
	HINTERNET hFtp;

	hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	hFtp = InternetConnect(hInternet, L"", INTERNET_DEFAULT_FTP_PORT, L"", L"", INTERNET_SERVICE_FTP, 0, 0);
	

	if (FtpPutFile(hFtp, L"c:\\log.txt", L"test.txt", FTP_TRANSFER_TYPE_BINARY, 0))
	{
		MessageBox(NULL, L"Succesful", L"Title", NULL);
	}
	else
	{
		MessageBox(NULL, L"Failed", L"Title", NULL);
	}

	InternetCloseHandle(hFtp);
	InternetCloseHandle(hInternet);
	system("pause");
    return 0;
}

