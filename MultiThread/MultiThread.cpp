// Multithread.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;
int i = 0;

DWORD WINAPI thread1(__in LPVOID lpParameter) {
	while (1) {
		std::cout << " From Thread 1 \n";
		i = 1;
		if (GetKeyState(0x51) & 0x8000)
		{
			cout << "You Pressed: Q." << endl;// ALT key is down.
			return 0;
		}
		Sleep(1000);
	}

}
/*
DWORD WINAPI thread2(__in LPVOID lpParameter) {
	while (1) {
		std::cout << " From thread 2\n";
		Sleep(1000);

	}
}
*/
int main()
{
	DWORD threadID1;
	while (1) {
		cout << i << endl;
		cout << "In main process." << endl;
		Sleep(3000);
		if (i == 0) {
			HANDLE h1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread1, 0, 0, &threadID1);
			//	HANDLE h2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread2, 0, 0, &threadID2);
//			return 0;
		}
		//getchar();
	}
	return 0;
}