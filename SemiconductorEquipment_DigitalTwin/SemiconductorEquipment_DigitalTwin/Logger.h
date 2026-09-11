#pragma once
#include <iostream>
#include <vector>
#include <string>

class Logger {
	private:
		std::vector<std::string> history;
	public:
		Logger();
		void Log(const std::string& log);
		void PrintHistory();
		void ResetHistory();
};