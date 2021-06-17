// main.cpp
#include "Appender.h"
#include "Logger.h"
#include "log.h"
#include <iostream>

int main()
{
	std::shared_ptr<log::Appender> appender = std::make_shared<log::ConsoleAppender>();
	log::Logger logger;
	logger.addAppender(appender);
    std::cout << "default level INFO" << std::endl;
	LOG_WARN(logger, "warn");
	LOG_INFO(logger, "info");
	LOG_DEBUG(logger, "debug");
    std::cout << "setLevel WARN" << std::endl;
	logger.setLevel(log::LogLevel::WARN);
	LOG_WARN(logger, "warn");
	LOG_INFO(logger, "info");
	LOG_DEBUG(logger, "debug");
    std::cout << "setLevel DEBUG" << std::endl;
	logger.setLevel(log::LogLevel::DEBUG);
	LOG_WARN(logger, "warn");
	LOG_INFO(logger, "info");
	LOG_DEBUG(logger, "debug");
	return 0;
}