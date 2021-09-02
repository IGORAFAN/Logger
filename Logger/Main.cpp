//Дз спроектировать логер.Для этого делаем интерфейс ILogger с функцией 
//write(const std::string& message)
//Сделать наследника ConsoleLogger, который будет писать лог в консоль.
//Сделать для теста 100 потоков из мейна,
//каждый поток пишет в лог по 10 сообщений содержащих id потока,
//имя функции из которой пишется и любой текст.
//Когда начнете это писать вы увидете что что - то нужно синхронизировать.
//Дожидайтесь окончания потоков в мейне через WaitForMultipleObjects

#include "ConsoleLogger.h"
#include <thread>
#include <synchapi.h>

DWORD WINAPI MyThreadFunc(LPVOID lpParam) {
	bool isLocked = static_cast<bool>(lpParam);
	while (!isLocked){
		Sleep(1);
	}
	isLocked = true;
	for (size_t iter = 0; iter < 10; ++iter) {
		ConsoleLogger conslLog;
		conslLog.writeMsg("Thread is working. ThreadID: ");
		DWORD dwThreadId;
		conslLog.writeThreadId(dwThreadId = GetCurrentThreadId());
	}
	isLocked = false;
	return 0;
}

int main() {

	DWORD dwThreadId;
	LPVOID paramAboutLocked;
	HANDLE hThreads[100];
	for (size_t iter = 0; iter < 100; ++iter) {
		hThreads[iter] = CreateThread(NULL, 0, MyThreadFunc, &paramAboutLocked, 0, &dwThreadId);
	}
	WaitForMultipleObjects(100, hThreads, 0, INFINITE);

	for (size_t iter = 0; iter < 100; ++iter) {
		CloseHandle(hThreads[iter]);
	}

	return 0;
}