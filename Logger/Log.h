#pragma once
#include "ILogger.h"
#include "ConsoleLogger.h"

ILogger& Log() {
	static ConsoleLogger logger;
	return logger;
}

#define LOG(msg) Log().Write(__FUNCTION__, msg) 