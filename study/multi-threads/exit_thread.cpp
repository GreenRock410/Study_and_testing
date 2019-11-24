#include "pch.h"
#include "exit_thread.h"

#include <iostream>
#include <thread>
#include <windows.h>
#include <future>

study::multi_threads::exit_thread::test::test(int ID) : m_id(ID)
{
	std::cout << "ctor-" << m_id << std::endl;
}

study::multi_threads::exit_thread::test::~test()
{
	std::cout << "destructor-" << m_id << std::endl;
}

void study::multi_threads::exit_thread::exit_thread_destructors()
{
	study::multi_threads::exit_thread::test t(1);

	std::thread([]()
		{
			study::multi_threads::exit_thread::test t(2);
			Sleep(10000);

		}).detach();

	std::thread([]()
		{
			study::multi_threads::exit_thread::test t(3);
			Sleep(100);
			exit(23);

		}).detach();


	Sleep(2000);

	exit(0);
}

/* OUTPUT

ctor-1
ctor-2
ctor-3

C:\GitHub\GreenRock410\Repos\Study_and_testing\study\Debug\multi-threads.exe (process 8200) exited with code 23.
Press any key to close this window . . .


=> Kdyz jiny thread ukonci process, tak v zadnych` threadech nedojde k volani destruktoru a unwindu stacku!!!
*/