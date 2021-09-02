#include <windows.h>
#include <iostream>
#include "ConsoleLogger.h"

void ConsoleLogger::Write(const std::string& context, const std::string& message)
{   
    EnterCriticalSection(&m_cs);
	std::cout << "[" << context << "][" << GetCurrentThreadId() << "] " << message << "  " << std::endl;	
	LeaveCriticalSection(&m_cs);
}