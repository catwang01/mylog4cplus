
#pragma once
#include <string>
#include "LogLevel.h"

namespace log
{
	class LoggingEvent
	{
	public:
		std::string message;
		int lineno;
		LogLevel level;
		std::string filename;
		LoggingEvent(const std::string &message,
			     int lineno,
			     const std::string& filename,
			     LogLevel level = LogLevel::INFO)
			      : message(message), lineno(lineno), filename(filename), level(level) {}
	};
};