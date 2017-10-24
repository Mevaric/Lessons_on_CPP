// variable.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS 1
#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
/*
const std::string currentDateTime() {
	time_t timev = time(0);
	struct tm tstruct;
	char buf[80];
	localtime_s(&tstruct ,&timev);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}
const std::string currentDateTime(time_t &t) {
	time_t timev = time(0);
	struct tm tstruct;
	char buf[80];
	t = timev;
	localtime_s(&tstruct, &timev);
	strftime(buf, sizeof(buf), "%X", &tstruct);
	return buf;
}*/
int main()
{
	double * p = new double();
	long * pl = new long();
	int Int = 8, max_int = (0b01111111111111111111111111111111), min_int = 1 << 31;
	std::cout << "Size int byte: " << sizeof(int) << "byte   bits : " << 8*sizeof(int)
		<< "bit   Current Value :" << Int << " Max value : " << max_int 
		<< " Min value : "<< min_int << std::endl;

	std::cout << "Bool : size :" << sizeof(bool) << std::endl
		<< "Char : size :" << sizeof(char) << std::endl
		<< "Float : size :" << sizeof(float) << std::endl
		<< "Double : size :" << sizeof(double) << std::endl
		<< "Long : size :" << sizeof(double) << std::endl
		<< "Pointer double : size :" << sizeof(p) << std::endl
		<< "Pointer long : size :" << sizeof(pl) << std::endl;
	std::cin.get();
	return 0;
}

