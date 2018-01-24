//TODO: LIST FILE IN DIR :(DOING)
//TODO: READ FILES :(PLAN)
//TODO: WRITE IN FILE :(PLAN)

#include <string>
#include<iostream>
#include<filesystem>
namespace fs = std::experimental::filesystem;
int main()
{
	std::string path = "\.";
	for (auto & p : fs::directory_iterator(path))
	{
		std::cout << p << std::endl;
	}
	system("pause");
}
/////////////// WINAPI
//#include <windows.h>
//#include <stdio.h>
//#include <tchar.h>
//#include <strsafe.h>
//void DisplayErrorBox(LPTSTR lpszFunction);
//WINAPI
//int _tmain(int argc, char *argv[]) 
//{
//	WIN32_FIND_DATA ffd;
//	LARGE_INTEGER filesize;
//	TCHAR szDir[MAX_PATH];
//	size_t lenght_of_arg;
//	HANDLE hFind = INVALID_HANDLE_VALUE;
//	DWORD dwError = 0;
//
//	if (argc != 2)
//	{
//		_tprintf(TEXT("\nUsage: %s <dir name>\n"), argv[0]);}
//	StringCchLength(argv[1], MAX_PATH, &lenght_of_arg);
//
//	if (lenght_of_arg > (MAX_PATH - 3))
//	{
//		_tprintf(TEXT("\nDirectory path is too long\n"));
//	}
//
//	_tprintf(TEXT("\nTarget: %s \n\n"), argv[1]);
//
//	StringCchCopy(szDir, MAX_PATH, argv[1]);
//	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));
//	
//	hFind = FindFirstFile(szDir, &ffd);
//
//	if (INVALID_HANDLE_VALUE == hFind)
//	{
//		DisplayErrorBox(LPTSTR("FindFirstFile"));
//		return dwError;
//	}
//
//	// List all the files in the directory with some info about them.
//
//	do
//	{
//		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
//		{
//			_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
//		}
//		else
//		{
//			filesize.LowPart = ffd.nFileSizeLow;
//			filesize.HighPart = ffd.nFileSizeHigh;
//			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
//		}
//	} while (FindNextFile(hFind, &ffd) != 0);
//
//	dwError = GetLastError();
//	if (dwError != ERROR_NO_MORE_FILES)
//	{
//		DisplayErrorBox(LPTSTR("FindFirstFile"));
//	}
//
//	FindClose(hFind);
//	system("PAUSE");
//	return dwError;
//}
//void DisplayErrorBox(LPTSTR lpszFunction)
//{
//	LPVOID lpMsgBuf;
//	LPVOID lpDisplayBuf;
//	DWORD dw = GetLastError();
//
//	FormatMessage(
//		FORMAT_MESSAGE_ALLOCATE_BUFFER |
//		FORMAT_MESSAGE_FROM_SYSTEM |
//		FORMAT_MESSAGE_IGNORE_INSERTS,
//		NULL,
//		dw,
//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//		(LPTSTR)&lpMsgBuf,
//		0, NULL);
//
//	// Display the error message and clean up
//
//	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
//		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
//	StringCchPrintf((LPTSTR)lpDisplayBuf,
//		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//		TEXT("%s failed with error %d: %s"),
//		lpszFunction, dw, lpMsgBuf);
//	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
//
//	LocalFree(lpMsgBuf);
//	LocalFree(lpDisplayBuf);
//}