#include <iostream>
#include <chrono>
#include <format>
#include "notifiable.h"

template<typename C>
concept HasFullDate = requires(C obj) {
	obj.created_at;
	obj.created_hour;
	obj.created_minute;
	obj.created_second;
};

template<typename C>
concept HasDateOnly = requires(C obj) {
	obj.created_at;
};

inline std::chrono::year_month_day nowDate()
{
	return std::chrono::floor<std::chrono::days>(
		std::chrono::system_clock::now());
}

#pragma once
template <typename T>
class base : public notifiable
{
public:
	T id{};
	std::chrono::year_month_day created_at{
		nowDate()
	};

	explicit base(const T& id) : id(id)
	{
		// a classe base sempre dá subscribe o handler para tratar as notificações
		this->subscribe([this](const notification& myNotification) {
			std::cout << std::format(
				"Notification event invoked by \"{}\" with message: \"{}\", at: {}\n",
				myNotification.property,
				myNotification.message,
				base::getDataStr(myNotification)
			);
			});
	}

	template<typename D>
	static std::string getDataStr(const D& obj)
	{
		if constexpr (HasFullDate<D>)
		{
			return std::format("{:02}/{:02}/{}, {:02}:{:02}:{:02}",
				static_cast<unsigned>(obj.created_at.day()),
				static_cast<unsigned>(obj.created_at.month()),
				static_cast<int>(obj.created_at.year()),
				obj.created_hour.count(),
				obj.created_minute.count(),
				obj.created_second.count()
			);
		}
		else if constexpr (HasDateOnly<D>)
		{
			return std::format("{:02}/{:02}/{}",
				static_cast<unsigned>(obj.created_at.day()),
				static_cast<unsigned>(obj.created_at.month()),
				static_cast<int>(obj.created_at.year())
			);
		}
		return "[ERR] empty date.";
	}
};
