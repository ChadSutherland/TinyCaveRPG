// Chad Sutherland
// 5/12/2019
#pragma once
#ifndef PASSWORD_H
#define PASSWORD_H
#include <fstream>
#include <string>
using namespace std;

class Password {
private:
	string password;
public:
	Password(string password);
	void setPassword(string password);

	void validatePassword(const string *passwordPtr);
	bool isValidLength(const string *passPtr);
	bool hasUppercase(const string *passPtr);
	bool hasLowercase(const string *passPtr);
	bool hasDigit(const string *passPtr);
	bool hasNoRepeatDigit(const string * passPtr);
	bool hasNoSequentialDigit(const string * passPtr);
	bool hasValidSpecialChar(const string *passPtr);
};
#endif