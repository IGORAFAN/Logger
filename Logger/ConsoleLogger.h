#pragma once
#include "ILogger.h"

class ConsoleLogger : public ILogger
{
public:
	ConsoleLogger() {
		InitializeCriticalSection(&m_cs);
	}

	~ConsoleLogger() {
		DeleteCriticalSection(&m_cs);
	}
	void Write(const std::string& context, const std::string& message) override;

private:
	CRITICAL_SECTION m_cs = {};
};

