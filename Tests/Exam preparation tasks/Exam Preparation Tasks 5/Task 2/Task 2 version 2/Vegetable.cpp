
#include "Vegetable.hpp"

Vegetable::Vegetable(const std::string& name, const double& price, const size_t& calories, const std::string& sort)
	: StoreItem(name, price, calories, Type::vegetable), _sort(sort)
{
}

std::string Vegetable::getSort() const
{
	return this->_sort;
}

void Vegetable::setSort(const std::string& sort)
{
	this->_sort = sort;
}

bool Vegetable::operator==(const Vegetable& v) const
{
	return this->_sort == v._sort;
}

StoreItem* Vegetable::clone() const
{
	return new Vegetable(*this);
}
