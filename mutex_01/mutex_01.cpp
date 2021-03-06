// mutex_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>

std::condition_variable foo;
std::mutex mtx;
void secondThread()
{
	while (true)
	{
		//foo.wait(std::unique_lock<std::mutex>(mtx));
		std::unique_lock<std::mutex> lk(mtx);
		foo.wait(lk);
		std::cout << "......SecondThread....\n";
	}
}
int main()
{
	std::thread subThread = std::thread(&secondThread);
	int count = 0;
	while (true)
	{
		if (count % 10 == 0) {
			foo.notify_one();
		}
		std::cout << "Hi, I am main thread.......\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		count++;
	}
    return 0;
}

