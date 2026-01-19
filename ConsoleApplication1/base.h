#include <iostream>
#include <chrono>
#include <format>
#include "notifiable.h"

#pragma once
template <typename T>
class base : public notifiable
{
public:
	T id{};
	std::chrono::year_month_day created_at{
		std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now())
	};

	base(const T& id) : id(id)
	{
		// a classe base sempre dá subscribe o handler para tratar as notificações
		this->subscribe([](notification myNotification) {
			std::cout << std::format(
				"Notification event invoked by \"{}\" with message: \"{}\", at: {}\n",
				myNotification.property,
				myNotification.message,
				std::format("{:02}/{:02}/{}, {:02}:{:02}:{:02}",
					static_cast<unsigned>(myNotification.created_at.day()),
					static_cast<unsigned>(myNotification.created_at.month()),
					static_cast<int>(myNotification.created_at.year()),
					myNotification.created_hour.count(),
					myNotification.created_minute.count(),
					myNotification.created_second.count()
				)
			);
			});
	}

	std::string getDataStr()
	{
		std::string dataStr = std::format("{:02}/{:02}/{}",
			static_cast<unsigned>(created_at.day()),
			static_cast<unsigned>(created_at.month()),
			static_cast<int>(created_at.year())
		);
		return dataStr;
	}
};
