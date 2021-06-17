#include "LogLevel.h"
#define LOG(logger, message, LEVEL)  logger.log(message, __LINE__, __FILE__, log::LEVEL)
#define LOG_INFO(logger, message) LOG(logger, message, INFO)
#define LOG_DEBUG(logger, message) LOG(logger, message, DEBUG)
#define LOG_WARN(logger, message) LOG(logger, message, WARN)