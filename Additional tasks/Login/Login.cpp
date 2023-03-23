
#include "login.h"

Login::Login() : sessionType(0) {
	username = new char[CHAR_SIZE];
	strcpy(username, "1234");

	password = new char[CHAR_SIZE];
	strcpy(password, "1234");
}

Login::Login(char* user) : sessionType(1) {
	int size = strlen1(user);
	username = new char[size + 1];
	strcpy(this->username, user);

	int t;
	std::cout << "Password length: ";
	std::cin >> t;
	std::cout << std::endl;
	password = new char[t + 1];
	std::cin >> password;
}


Login::Login(char* user, char* pass) : sessionType(1) {
	int size = strlen1(user);
	username = new char[size];

	size = strlen1(pass);
	password = new char[size];

	strcpy(this->username, user);
	strcpy(this->password, pass);
}

Login::Login(char* user, char* pass, int session) : sessionType(session) {
	int size = strlen1(user);
	username = new char[size];

	size = strlen1(pass);
	password = new char[size];

	strcpy(this->username, user);
	strcpy(this->password, pass);
}

Login::Login(const Login& l) {
	int size = strlen1(username);
	username = new char[size];

	size = strlen1(password);
	password = new char[size];

	strcpy(this->username, l.username);
	strcpy(this->password, l.password);
	sessionType = l.sessionType;
}

void Login::setUsername(const char* user) {
	int size = strlen1(user);
	username = new char[size];

	strcpy(this->username, user);
}

void Login::setPassword(const char* pass) {
	int size = strlen(pass);
	password = new char[size];
	strcpy(this->password, pass);
}

void Login::setSession(const int session) {
	sessionType = session;
}

void Login::print() const {
	std::cout << "Username: " << username << "\nPassword: " << password
		<< "\nSession: " << sessionType;
}

char* Login::getUsername() const {
	return username;
}

char* Login::getPassword() const {
	return password;
}

int Login::getSession() const {
	return sessionType;
}

int Login::strlen1(const char* str) {
	int size = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		size++;
	}
	return size;
}