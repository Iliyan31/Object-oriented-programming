
#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension) {}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
	bool flag = false;
	for (int i = 0; i < database.size(); i++) {
		if (this->database[i].first == entry.first) {
			flag = true;
		}
	}
	if (flag == false) {
		this->database.push_back(entry);
	}
	else {
		throw std::invalid_argument("There is such key in the database!");
	}
	
}

int KeyValueDatabase::get_value(const std::string& key) const {
	for (int i = 0; i < database.size(); i++) {
		if (database[i].first == key) {
			return database[i].second;
		}
	}
	throw std::invalid_argument("There isn't such key in the database!");
}

bool KeyValueDatabase::operator==(const Comparable* c) const {
	const KeyValueDatabase* keys = dynamic_cast<const KeyValueDatabase*>(c);
	if (keys) {
		if (this->database.size() != keys->database.size()) return false;
		for (int i = 0; i < this->database.size(); i++) {
			if (this->database[i]!=keys->database[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool KeyValueDatabase::operator!=(const Comparable* c) const {
	const KeyValueDatabase* keys = dynamic_cast<const KeyValueDatabase*>(c);
	if (keys) {
		if (this->database.size() != keys->database.size()) return true;
		for (int i = 0; i < this->database.size(); i++) {
			if ((this->database[i].first == keys->database[i].first) && (this->database[i].second != keys->database[i].second)) {
				return true;
			}
			if ((this->database[i].first != keys->database[i].first) && (this->database[i].second == keys->database[i].second)) {
				return true;
			}
		}
		return false;
	}
	return true;
}

std::string KeyValueDatabase::debug_print() const {	
	std::string all;
	for (int i = 0; i < database.size(); i++) {
		all += "{";
		all += database[i].first;
		all += ":";
		all += std::to_string(database[i].second);
		all += "}";
		all += "\n";
	}
	return all;
}

std::string KeyValueDatabase::to_string() const {
	std::string all;
	all += this->name;
	all += "\n";
	all += this->location;
	all += "\n";
	all += this->extension;
	all += "\n";
	for (int i = 0; i < database.size(); i++) {
		all += database[i].first;
		all += ":";
		all += std::to_string(database[i].second);
		all += "\n";
	}
	return all;
}

void KeyValueDatabase::from_string(const std::string& str) {
	this->database.clear();
	int counter = 0;
	std::string name;
	std::string location;
	std::string extension;
	std::string temp;
	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '\n') {
			counter++;
		}
		if (counter == 0 && str[i] != '\n') {
			name += str[i];
		}
		if (counter == 1 && str[i] != '\n') {
			location += str[i];
		}
		if (counter == 2 && str[i] != '\n') {
			extension += str[i];
		}
		if (counter > 2 && str[i] != '\n') {
			temp += str[i];
		}
		if (counter > 2 && str[i] == '\n') {
			if (temp != "") {
				std::string name2;
				int tempValue = 0;
				int count = 0;
				for (int j = 0; j < temp.size(); j++) {
					if (temp[j] == ':') {
						count++;
					}
					if (count == 0 && temp[j] != ':') {
						name2 += temp[j];
					}
					if (count == 1 && temp[j] != '\n' && temp[j]!=':') {
						tempValue = (tempValue * 10 + (temp[j] - '0'));
					}
				}
				std::pair<std::string, int> pair;
				pair.first = name2;
				pair.second = tempValue;
				this->database.push_back(pair);
				temp = "";
			}
		}
	}

	this->name = name;
	this->location = location;
	this->extension = extension;
}

Object* KeyValueDatabase::clone() const {
	return new KeyValueDatabase(*this);
}