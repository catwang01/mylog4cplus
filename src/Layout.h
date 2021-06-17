
#pragma once
#include <iostream>
#include "LoggingEvent.h"
#include <string>

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
				return "filename: " + event.filename + " - lineno: " + std::to_string(event.lineno) + " - " + event.message;
			}
	};
};