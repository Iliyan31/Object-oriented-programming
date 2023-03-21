
#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension) {}

void Document::write_line(const std::string& line) {
	this->document.push_back(line);
}

std::string Document::read_line() {
	if (document.size() < this->line) {
		throw std::out_of_range("You are going out of range!");
	}
	this->line++;
	return this->document[line - 2];
}
std::string Document::read_line(const unsigned& line) {
	if (this->document.size() < line || line < 1) {
		 throw std::out_of_range("You are going out of range!");
	}
	this->line = line + 1;
	return this->document[line - 1];
}

bool Document::operator==(const Comparable* c) const {
	const Document* doc = dynamic_cast<const Document*>(c);
	if (doc) {
		if (this->document.size() != doc->document.size()) return false;
		for (int i = 0; i < this->document.size(); i++) {
			if (this->document[i] != doc->document[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
	
}

bool Document::operator!=(const Comparable* c) const {
	const Document* doc = dynamic_cast<const Document*>(c);
	if (doc) {
		if (this->document.size() != doc->document.size()) return true;
		for (int i = 0; i < this->document.size(); i++) {
			if (this->document[i] == doc->document[i]) {
				return false;
			}
		}
		return true;
	}
	return true;
}
	

std::string Document::debug_print() const {		
	std::string all;
	for (int i = 0; i < document.size(); i++) {
		all += "Line ";
		all += std::to_string(i + 1);
		all += ":";
		all += document[i];
		all += "\n";
	}
	return all;
}

std::string Document::to_string() const {
	std::string all;
	all += this->name;
	all += "\n";
	all += this->location;
	all += "\n";
	all += this->extension;
	all += "\n";
	for (int i = 0; i < document.size(); i++) {
		all += document[i];
		all += "\n";
	}
	return all;
}

void Document::from_string(const std::string& str) {
	this->document.clear();
	int counter = 0;
	std::string name;
	std::string location;
	std::string extension;
	std::string temp;
	for (int i = 0; i < str.size(); i++) {
		
		if (str[i] == '\n') {
			counter++;
		}
		if (counter == 0 && str[i]!='\n') {
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
				this->document.push_back(temp);
				temp = "";
			}
		}
	}

	this->name = name;
	this->location = location;
	this->extension = extension;
}

Object* Document::clone() const {
	return new Document(*this);
}