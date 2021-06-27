
#pragma once
#include "LogLevel.h"
#include <string>

#define LOG_CUSTOM_DEBUG(logger, message) logger.log(message, __LINE__, __FILE__, CUSTOM_DEBUG)


using log::LogLevel;
using log::LogLevelManager;

const LogLevel CUSTOM_DEBUG =  150;
class RegisterLevel
{
	public:
		RegisterLevel(const LogLevel& level, const std::string& s) {
			LogLevelManager& manager = LogLevelManager::getInstance();
			manager.addLevel(level, s);
		}
};
RegisterLevel registerLevel(CUSTOM_DEBUG, "CUSTOM_DEBUG");