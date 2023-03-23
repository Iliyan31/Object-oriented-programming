
#include "UserInfo.h"

void UserInfo::print() const {
	std::cout << "Username: " << username << "\nPassword: " << password;
}

UserInfo::UserInfo() : username(" "), password(" ") {}

UserInfo::UserInfo(std::string user) : username(user), password(" ") {}

UserInfo::UserInfo(std::string user, std::string pass) : username(user), password(pass) {}

UserInfo::UserInfo(const UserInfo& u) : username(u.username), password(u.password) {}