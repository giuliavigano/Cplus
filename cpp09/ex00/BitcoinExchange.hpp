#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <exception>


class ErrorOpeningThisFile : std::exception {
public:
	virtual const char* what() const throw() {
		return "Error: could not open this file!";
	}
};

class NotAValidNumber : std::exception {
public:
	virtual const char* what() const throw() {
		return "Error: not a positive number!";
	}
};

class NumberTooLarge : std::exception {
public:
	virtual const char* what() const throw() {
		return "Error: too large number (>1000) !";
	}
};

class NotAValidDate : std::exception {
public:
	virtual const char* what() const throw() {
		return "Error: not a valid date!";
	}
};

#endif