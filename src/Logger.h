
#pragma once
#include "Appender.h"
#include "LoggingEvent.h"
#include <vector>

namespace log
{
	class Logger
	{
		typedef std::shared_ptr<Appender> AppendPtr;
		typedef std::vector<AppendPtr> AppenderList;
		public:
			Logger(Logger* parent=NULL, LogLevel level=LogLevel::INFO): parent(parent), level(level) {}
			void addAppender(AppendPtr appender)
			{
				appenderList.push_back(appender);
			}
			void log(const std::string& message, int lineno, const std::string& filename, LogLevel level)
			{
				if (this->level > level) return ;
				LoggingEvent event(message, lineno, filename, level);
				for (auto& appender: appenderList)
				{
					appender->append(event);
				}
			}
			void setLevel(LogLevel level) {
				this->level = level;
			}
			LogLevel getLevel(LogLevel level) const
			{
				return level;
			}
		private:
			LogLevel level;
			Logger* parent;
			AppenderList appenderList;

	};
};