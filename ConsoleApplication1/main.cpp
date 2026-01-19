#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <format>
#include "item.h"
#include "base.h"
#include "notification.h"

auto main() -> int
{
	auto myItem = std::make_unique<item>(111);
	auto myItem2 = std::make_unique<item>(469);

	return 0;
}