#pragma once
#include <iostream>
#include <string>

enum class Type {
	eat,
	drink,
	none
};

class Item {
public:
	Item(const std::string& name = " ", const std::string& code = " ", const double& price = 0, Type type = Type::none);

	std::string getName() const;
	std::string getCode() const;
	double getPrice() const;

	void setName(const std::string& name);
	void setCode(const std::string& code);
	void setprice(const double& price);

	virtual Item* clone() const = 0;
	virtual ~Item() = default;
private:
	Type type;
	std::string name;
	std::string code;
	double price;
};