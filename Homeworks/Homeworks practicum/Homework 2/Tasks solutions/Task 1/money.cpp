
/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Iliyan Yordanov
* @idnumber 62546
* @task 1
* @compiler VC
*/

#include "money.hpp"

void Money::templ(unsigned int num1, unsigned int num2) {
	std::pair<unsigned int, std::string> temp1;
	temp1.first = num1;
	temp1.second = "gold";
	std::pair<unsigned int, std::string> temp2;
	temp2.first = num2;
	temp2.second = "silver";
	money.push_back(temp1);
	money.push_back(temp2);
}

Money::Money() {
	templ(0, 0);
}

Money::Money(std::vector<std::pair<unsigned int, std::string>> _money) {
	if (_money[1].first >= 100) {
		int temp = _money[1].first;
		int temp2 = _money[1].first;
		for (int i = 0; i < 2; i++) {
			temp /= 10;
		}
		_money[0].first += temp2;
		_money[1].first = temp - 100 * temp2;
	}
	templ(_money[0].first, _money[1].first);
}

Money::Money(const Money& m) {
	templ(m.money[0].first, m.money[1].first);
}

void Money::addMoney(std::string typ, unsigned int sum) {

	if (typ == "gold" || typ == "silver") {
		for (int i = 0; i < money.size(); i++) {
			if (money.at(i).second == typ) {
				money.at(i).first += sum;
				if (money.at(i).second == "silver" && money.at(i).first >= 100) {
					int temp = money.at(i).first;
					int tempGoldSum = money.at(i).first;
					for (int i = 0; i < 2; i++) {
						tempGoldSum /= 10;
					}
					money.at(1).first = temp - 100 * tempGoldSum;
					money.at(0).first += tempGoldSum;
				}
			}
		}
	}
	else {
		printf("Wrong input!\n");
	}
}

void Money::takeMoney(std::string typ, unsigned int sum) {

	if (typ == "gold" || typ == "silver") {
		for (int i = 0; i < money.size(); i++) {
			if (money.at(i).second == typ) {
				int temp = money.at(i).first;
				temp -= sum;
				if (money.at(i).second == "gold" && temp < 0) {
					printf("You can't take that much golden coins!\n");
					break;
				}
				if (money.at(i).second == "silver" && temp < 0) {
					if (money.at(0).first != 0) {
						
						int temp2 = abs(temp);
						for (int i = 0; i < 2; i++) {
							temp2 /= 10;
						}
						temp2 += 1;
						int temp3 = money.at(0).first - temp2;
						int temp4 = money.at(0).first* 100 - abs(temp);
						if (temp3 < 0 && temp4!=0) {
							printf("You cant take that much coins!\n");
							break;
						}
						else if(temp3==-1 && temp4 ==0) {
							money.at(0).first = 0;
							money.at(1).first = 0;
						}
						else {
							money.at(0).first -= temp2;
							money.at(1).first = 100 * temp2 + temp;
						}
					}
					else {
						printf("You can't take that much silver coins!\n");
						break;

					}
				}
			}
		}
	}
	else {
		printf("Wrong input!\n");
	}
}

void Money::printMoney() const {
	for (int i = 0; i < 2; i++) {
		std::cout << money.at(i).first << " ";
		std::cout << money.at(i).second;
		std::cout << std::endl;
	}
}

void Money::setEmpty(){
	money[0].first = 0;
	money[1].first = 0;
}

Money& Money::operator+=(const Money& m) {
	if (this != &m) {
		for (int i = 0; i < money.size(); i++) {
			money.at(i).first += m.money.at(i).first;			
			if (money.at(1).first >= 100) {
				int temp = money.at(1).first;
				int tempGoldSum = money.at(1).first;
				for (int i = 0; i < 2; i++) {
					tempGoldSum /= 10;
				}
				money.at(1).first = temp - 100 * tempGoldSum;
				money.at(0).first += tempGoldSum;
			}
		}
	}
	return *this;
}

Money& Money::operator-=(const Money& m) {
	if (this != &m) {
		for (int i = 0; i < money.size(); i++) {
			int temp = money.at(i).first;
			temp -= m.money.at(i).first;
			if (i==0 && temp < 0) {
				break;
			}
			if (i==1 && temp < 0) {
				if (money.at(0).first != 0) {

					int temp2 = abs(temp);
					for (int i = 0; i < 2; i++) {
						temp2 /= 10;
					}
					temp2 += 1;
					int temp3 = money.at(0).first - temp2;
					int temp4 = money.at(0).first * 100 - abs(temp);
					if (temp3 < 0 && temp4 != 0) {
						break;
					}
					else if (temp3 == -1 && temp4 == 0) {
						money.at(0).first = 0;
						money.at(1).first = 0;
					}
					else {
						money.at(0).first -= temp2;
						money.at(1).first = 100 * temp2 + temp;
					}
				}
				else {
					break;
				}
			}
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Money& in) {
	for (int i = 0; i < 2; i++) {
		out << in.money.at(i).first << " " << in.money.at(i).second << " ";
	}
	return out;
}