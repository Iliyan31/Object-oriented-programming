
#include <iostream>
#include <cstring>
#include <stdlib.h>

class MyString {
public:
	MyString();
	MyString(const MyString& str);
	MyString(const char* str);
	~MyString();

	int length() const;
	const char* getString() const;

	MyString& operator=(const MyString& str);	// =
	const char* operator=(const char*);			// =
	bool operator==(const MyString& str);		// ==
	bool operator==(const char* str);			// ==
	bool operator!=(const MyString& str);		// !=
	bool operator!=(const char* str);			// !=
	bool operator>(const MyString& str);		// >
	bool operator>(const char* str);			// >
	bool operator<(const MyString& str);		// <
	bool operator<(const char* str);			// <
	bool operator>=(const MyString& str);		// >=
	bool operator>=(const char* str);			// >=
	bool operator<=(const MyString& str);		// <=
	bool operator<=(const char* str);			// <=
	friend bool operator==(const char* str1, const MyString& str2);
	friend bool operator!=(const char* str1, const MyString& str2);
	friend bool operator>(const char* str1, const MyString& str2);
	friend bool operator<(const char* str1, const MyString& str2);
	friend bool operator>=(const char* str1, const MyString& str2);
	friend bool operator<=(const char* str1, const MyString& str2);

	void print() const {
		for (int i = 0; i < len; i++) {
			std::cout << str[i];
		}
	}

private:
	char* str;
	unsigned int len;
};

MyString::MyString() : len(0){
	str = new char[1];
	str[0] = '\0';
}

MyString::MyString(const MyString& r){
	if (r.str == nullptr) {
		str = new char[1];
		str[0] = '\0';
	}
	else {
		this->str = new char[strlen(r.str) + 1];
		strcpy_s(str, strlen(r.str) + 1, r.str);
		this->len = r.len;
	}
}









int main() {

	return 0;
}