#pragma once
#include <string>

class ILogger {
public:
	virtual ~ILogger() {};
	virtual void Write(const std::string& context, const std::string& message) = 0;
};