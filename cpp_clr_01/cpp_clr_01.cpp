// cpp_clr_01.cpp : main project file.

#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	String ^ ch;
	ch = L"Hello Vlad";
    Console::WriteLine(L"Hello World");
	Console::WriteLine(ch);
	Console::ReadLine();
	delete ch;
	return 0;
	
}
