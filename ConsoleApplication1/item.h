#include <iostream>
#include <format>
#include "base.h"

#pragma once
class item : public base<int>
{
public:
	item(const int& id) : base<int>(id)
	{
		auto myNotification = std::make_unique<notification>
			("Item", std::format("Item created at id [{}]", this->id));

		AddNotification(*myNotification);
	}
};

