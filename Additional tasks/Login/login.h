#pragma once

#include <iostream>
#include <cstring>

const int CHAR_SIZE = 5;

class Login {
public:
	Login();
	Login(char* user);
	Login(char*, char*);
	Login(char*, char*, int);
	Login(const Login&);

	void setUsername(const char*);
	void setPassword(const char*);
	void setSession(const int);

	void print() const;
	char* getUsername() const;
	char* getPassword() const;
	int getSession() const;
	int strlen1(const char* str);

private:
	char* username;
	char* password;
	int sessionType;
};