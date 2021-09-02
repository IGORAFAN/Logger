#include <sstream>
#include <windows.h>
#include "Log.h"

DWORD WINAPI MyCreateFunction(PVOID lParam) 
{
	for (size_t i = 0; i < 10; ++i) {
		LOG("");
	}
	return 0;
}

int main()
{
	LOG("Start");
	const int threadsCount = 100;
	DWORD threadsId[threadsCount] = {};
	HANDLE threads[threadsCount] = {};
	for (size_t i = 0; i < threadsCount; ++i) {
		LOG("CreateThread");
		threads[i] = CreateThread(0, 0, MyCreateFunction, 0, 0, &threadsId[i]);
		if (threads[i] == INVALID_HANDLE_VALUE) {
			return GetLastError();
		}
	}
	LOG("WaitForMultipleObjects");
	WaitForMultipleObjects(threadsCount, threads, TRUE, INFINITE);
	for (size_t i = 0; i < threadsCount; ++i) {
		if (threads[i] != INVALID_HANDLE_VALUE) {
			CloseHandle(threads[i]);
		}
	}
	system("pause");
}
