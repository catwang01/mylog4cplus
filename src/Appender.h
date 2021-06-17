
#pragma once
#include "LoggingEvent.h"
#include "LogLevel.h"
#include <iostream>
#include "Layout.h"
#include <vector>
#include <memory>

namespace log
{
	class Appender
	{
	public:
		virtual void append(LoggingEvent &) = 0;
		virtual void setLayout(std::shared_ptr<Layout> &layout) = 0;
		Appender(LogLevel level = LogLevel::INFO,
			 std::shared_ptr<Layout> layoutPtr = NULL) : level(level), layoutPtr(layoutPtr) {}

	protected:
		LogLevel level;
		std::shared_ptr<Layout> layoutPtr;
	};

	class ConsoleAppender : public Appender
	{
	public:
		ConsoleAppender() : Appender(LogLevel::INFO, std::make_shared<SimpleLayout>()) {}
		void append(LoggingEvent &event) override
		{
			std::cout << layoutPtr->format(event) << std::endl;
		};
		void setLayout(std::shared_ptr<Layout> &layout) override
		{
			layoutPtr = layout;
		}
	};
}