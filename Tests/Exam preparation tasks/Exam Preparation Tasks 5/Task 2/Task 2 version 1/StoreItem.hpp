
#ifndef STOREITEM
#define STROEITEM
#include <iostream>
#include <string>

enum class TypeItem {
	None,
	fruit,
	vegetable
};

class StoreItem {
protected:
	TypeItem type;
	double price;
	unsigned int calories;
public:
	StoreItem(TypeItem _type = TypeItem::None, double _price = 0, unsigned int _calories = 0);
	TypeItem getItemType() const;
	double getPrice() const;
	unsigned int getCalories() const;
	void setItemType(const TypeItem& _type);
	void setPrice(const double& _price);
	void setCalories(const unsigned int& _calories);
	virtual void print() const;
	virtual StoreItem* clone() = 0;
	virtual ~StoreItem() = default;
};

#endif // !STOREITEM