#pragma once
#include "StoreItem.hpp"

class Vegetable : public StoreItem {
public:
	Vegetable(const std::string& name = " ", const double& price = 0, const size_t& calories = 0, const std::string& sort = " ");

	std::string getSort() const;
	void setSort(const std::string& sort);

	bool operator==(const Vegetable& v) const;

	StoreItem* clone() const;
	~Vegetable() = default;
private:
	std::string _sort;
};