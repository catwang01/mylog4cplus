
#pragma once
#include <iostream>
#include "LoggingEvent.h"
#include <string>
#include "LogLevel.h"

namespace log
{
	class Layout {
		public:
			virtual std::string format(const LoggingEvent& event) const = 0;
	};

	class SimpleLayout: public Layout
	{
		public:
			std::string format(const LoggingEvent& event) const override
			{
				return "filename: " + event.filename + " - lineno: " + std::to_string(event.lineno) + " - level: " + LogLevelManager::getInstance().Level2Str(event.level) + " " + event.message;
			}
	};
};