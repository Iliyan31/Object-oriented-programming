#pragma once

#include <iostream>
#include <cstring>

//const int SIZE_Name = 20;
//const int SIZE_PASS = 100;

class UserInfo {
public:
	void print() const;
	UserInfo();
	UserInfo(std::string user);
	UserInfo(std::string user, std::string pass);
	UserInfo(const UserInfo& u);
private:
	//char name[SIZE_Name];
	//char password[SIZE_PASS];

	std::string username;
	std::string password;
};