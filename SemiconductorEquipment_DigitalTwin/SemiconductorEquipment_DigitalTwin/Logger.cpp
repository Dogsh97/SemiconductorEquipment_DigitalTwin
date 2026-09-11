#include "Logger.h"

Logger::Logger() 
{
}

void Logger::Log(const std::string& log){
	std::cout << log << '\n';
	history.push_back(log);
}

void Logger::PrintHistory() {
	std::cout << "==== Log ====\n";

	for (const auto& log : history) {
		std::cout << log << "\n";
	}
}
	

void Logger::ResetHistory() {
	history.clear();
}

