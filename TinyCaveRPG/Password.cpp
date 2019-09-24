// Chad Sutherland
// 5/12/2019
#include "Password.h"

Password::Password(string password) {
	try {
		setPassword(password);
	}
	catch (string exceptions) {
		throw exceptions;
	}
}

void Password::setPassword(string password) {
	try {
		validatePassword(&password);
		this->password = password;
	}
	catch (string exceptions) {
		throw exceptions;
	}
}

void Password::validatePassword(const string * passwordPtr) {
	bool passValid = true;
	string errorMsg = "Error:\n";

	if (!isValidLength(passwordPtr)) {
		errorMsg += "     Password must be between 8 and 15 characters long.\n";
		passValid = false;
	}

	if (!hasUppercase(passwordPtr)) {
		errorMsg += "     Password must contain at least one uppercase letter.\n";
		passValid = false;
	}

	if (!hasLowercase(passwordPtr)) {
		errorMsg += "     Password must contain at least one lowercase letter.\n";
		passValid = false;
	}

	if (!hasDigit(passwordPtr)) {
		errorMsg += "     Password must contain at least one digit.\n";
		passValid = false;
	}

	if (!hasNoRepeatDigit(passwordPtr)) {
		errorMsg += "     Password must not contain concurrently repeating digits (e.g. 11 or 22).\n";
		passValid = false;
	}

	if (!hasNoSequentialDigit(passwordPtr)) {
		errorMsg += "     Password must not contain sequential digits (e.g. 12 or 23).\n";
		passValid = false;
	}

	if (!hasValidSpecialChar(passwordPtr)) {
		errorMsg += "     Password must contain !, @, #, $ or % but no other special characters.\n";
		passValid = false;
	}

	if (!passValid)
		throw errorMsg;
}

// this function checks the length
bool Password::isValidLength(const string * passPtr) {
	if (passPtr->length() < 8 || passPtr->length() > 15)
		return false;
	else
		return true;
}

// this function checks for uppercase letter
bool Password::hasUppercase(const string * passPtr) {
	bool uppercase = false;

	for (int i = 0; i < passPtr->length(); i++)
		if (isupper((*passPtr)[i]))
			uppercase = true;

	return uppercase;
}

// this function checks for lowercase letter
bool Password::hasLowercase(const string * passPtr) {
	bool lowercase = false;

	for (int i = 0; i < passPtr->length(); i++)
		if (islower((*passPtr)[i]))
			lowercase = true;

	return lowercase;
}

// this function checks for numbers
bool Password::hasDigit(const string * passPtr) {
	bool digit = false;

	for (int i = 0; i < passPtr->length(); i++)
		if (isdigit((*passPtr)[i]))
			digit = true;

	return digit;
}

// this function checks for repeat digits
bool Password::hasNoRepeatDigit(const string * passPtr) {
	bool noRepeatDigit = true;

	for (int i = 0; i < passPtr->length(); i++)
		if (isdigit((*passPtr)[i]) && (*passPtr)[i] == (*passPtr)[i + 1])
			noRepeatDigit = false;

	return noRepeatDigit;
}

// this function checks for sequential digits
bool Password::hasNoSequentialDigit(const string * passPtr) {
	bool noSequentialDigit = true;

	for (int i = 0; i < passPtr->length(); i++)
		if (isdigit((*passPtr)[i]) && isdigit((*passPtr)[i + 1]) && (*passPtr)[i + 1] == (*passPtr)[i] + 1)
			noSequentialDigit = false;

	return noSequentialDigit;
}

// this function checks for valid and invalid special characters
bool Password::hasValidSpecialChar(const string * passPtr) {
	bool hasRequiredSpecialChar = false;
	bool hasInvalidChar = false;

	for (int i = 0; i < passPtr->length(); i++) {
		if
			((*passPtr)[i] == '!'
				|| (*passPtr)[i] == '@'
				|| (*passPtr)[i] == '#'
				|| (*passPtr)[i] == '$'
				|| (*passPtr)[i] == '%')
			hasRequiredSpecialChar = true;
		else if (ispunct((*passPtr)[i]))
			hasInvalidChar = true;
	}

	if (hasRequiredSpecialChar && !hasInvalidChar)
		return true;
	else
		return false;
}