#include <chrono>
#include <iostream>

#pragma once
class notification
{
public:
	std::string property{};
	std::string message{};
	std::chrono::year_month_day created_at {
		std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())
	};
	std::chrono::hours created_hour =
		std::chrono::duration_cast<std::chrono::hours>(
			std::chrono::system_clock::now().time_since_epoch()
		) % 24;
	std::chrono::minutes created_minute =
		std::chrono::duration_cast<std::chrono::minutes>(
			std::chrono::system_clock::now().time_since_epoch()
		) % 60;
	std::chrono::seconds created_second =
		std::chrono::duration_cast<std::chrono::seconds>(
			std::chrono::system_clock::now().time_since_epoch()
		) % 60;

	notification(std::string property, std::string message) : property(property), message(message)
	{
	}
};

