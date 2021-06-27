
#pragma once

#include "Mixin.h"
#include <unordered_map>
#include <string>

using std::unordered_map;

namespace log
{
	typedef int LogLevel;
	const LogLevel WARN = 200;
	const LogLevel INFO = 100;
	const LogLevel DEBUG = 0;
	const LogLevel NO_A_VALID = -1;

	class LogLevelManager : public Singleton<LogLevelManager>
	{
	public:
		LogLevelManager()
		{
			addLevel(WARN, "WARN");
			addLevel(INFO, "INFO");
			addLevel(DEBUG, "DEBUG");
			addLevel(NO_A_VALID, "NO_A_VALID");
		}
		const LogLevel &Str2Level(const std::string &s)
		{
			auto it = str2Level.find(s);
			if (it != str2Level.end())
				return str2Level[s];
			else
				return str2Level["NO_A_VALID"];
		}

		const std::string &Level2Str(const LogLevel &level)
		{
			auto it = level2Str.find(level);
			if (it != level2Str.end())
				return level2Str[level];
			else
				return level2Str[NO_A_VALID];
		}
		void addLevel(const LogLevel &level, const std::string &s)
		{
			if (level2Str.count(level))
			{
				std::cout << "There is already a level " << level2Str[level] << " with value" << level 
				<< "Please set a another value to the level\n";
			}
			else
			{
				level2Str[level] = s;
				str2Level[s] = level;
			}
		}
	private:
		unordered_map<std::string, LogLevel> str2Level;
		unordered_map<LogLevel, std::string> level2Str;
	};
};