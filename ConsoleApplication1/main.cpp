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
	//std::vector<std::unique_ptr<base<int>>> bases = {};
	//bases.emplace_back(std::make_unique<base<int>>(469));
	////bases.emplace_back(std::make_unique<base<int>>(369));
	////bases.emplace_back(std::make_unique<base<int>>(269));

	//std::ranges::sort(bases);

	//std::ranges::for_each(bases, [](const std::unique_ptr<base<int>>& b) {
	//	std::cout << "base id: " << b->id << std::endl;
	//	std::cout << "object created_at: " << b->getDataStr() << std::endl;
	//	});

	auto myItem = std::make_unique<item>(111);
	auto myItem2 = std::make_unique<item>(469);

	return 0;
}