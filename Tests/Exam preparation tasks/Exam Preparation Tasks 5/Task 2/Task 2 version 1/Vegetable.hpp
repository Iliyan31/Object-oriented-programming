
#ifndef VEGETABLE
#define VEGETABLE
#include "StoreItem.hpp"

class Vegetable : public StoreItem {
protected:
	std::string name;
	std::string sort;
public:
	Vegetable(const std::string & _name = " ", const std::string& _sort = " ");
	virtual std::string getName() const;
	std::string getSort() const;
	// setters
	bool operator==(const Vegetable& v);
};


#endif // !VEGETABLE
