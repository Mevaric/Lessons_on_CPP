// function.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
int Multiply(int a, int b)
{
	return a * b;
}
int MultiplyAndLog(int a, int b) {
	int res = a * b;
	std::cout << "res: " << res << std::endl;
	return res;
}
int main()
{
	int result = Multiply(5, 6);
	std::cout << "Result : " << result << std::endl;
	MultiplyAndLog(6, 8);
	std::cin.get();
    return 0;
}

