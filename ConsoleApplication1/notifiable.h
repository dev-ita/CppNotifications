#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <ranges>
#include <typeinfo>
#include "notification.h"

#pragma once
class notifiable
{
public:
	std::vector<notification> notifications = {};
	using Handler = std::function<void(notification)>;

	void AddNotification(const notification& notification)
	{
		this->notifications.push_back(notification);
		invokeNotificationEvent(notification);
	}

	void AddNotifications(const std::vector<notification>& notifications)
	{
		this->notifications.insert(this->notifications.end(), notifications.begin(), notifications.end());
		invokeNotificationsEvent(notifications);
	}

	void subscribe(const Handler& h)
	{
		handlers.emplace_back(h);
	}

	void invokeNotificationEvent(const notification& myNotification)
	{
		std::ranges::for_each(this->handlers, [&](const Handler& handler) {
			handler(myNotification);
			});
	}

	void invokeNotificationsEvent(const std::vector<notification>& notifications)
	{
		std::ranges::for_each(notifications, [&](const notification& notification) {
			std::ranges::for_each(this->handlers, [&](const Handler& handler) {
				handler(notification);
				});
			});
	}
private:
	std::vector<Handler> handlers = {};
};

