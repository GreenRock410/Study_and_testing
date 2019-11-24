// multi-threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "exit_thread.h"

#include <iostream>
#include <thread>
#include <windows.h>
#include <future>

void fce_1()
{
	Sleep(10000);
	std::cout << "fce1 World!\n";
	throw std::exception();
}

void fce_2()
{
	Sleep(2000);
}

int main()
{
	study::multi_threads::exit_thread::exit_thread_destructors();

 //   std::cout << "Hello World!\n"; 

	//std::future<void> result(std::async(std::launch::async, fce_1));
	////std::thread t1(fce_1);
	////t1.join();
	//fce_2();
	//std::cout << "main World!\n";
	//result.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
