/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:21:18 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/17 11:04:05 by giuliaviga       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& value) : database(value.database) {}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& val) {
    if (this != &val) {
        this->database = val.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::isValidValue(double value) {
	return (value >= 0 && value <= 1000);
}

void	BitcoinExchange::loadDatabase() {
	std::ifstream dataFile("data.csv");
	if (!dataFile)
		throw ErrorOpeningThisFile();
	std::string	line;
	getline(dataFile, line);
	while (getline(dataFile, line)) {
		size_t	com = line.find(',');
		if (com != std::string::npos) {
			std::string date = line.substr(0, com);
			float	value = std::atof((line.substr(com + 1)).c_str());
			database[date] = value;
		}
	}
}

float	BitcoinExchange::get_exchange_value(const std::string& date) {
	if (database.find(date) != database.end())
		return database[date];
	std::string	closest_date = findClosestDate(date);
	if (!closest_date.empty())
		return database[closest_date];
	return 0.0f;
}

std::string	BitcoinExchange::findClosestDate(const std::string& date) {
	std::map<std::string, float>::iterator	it = database.lower_bound(date);
	if (it == database.begin())
		return "";
	--it;
	return it->first;
}

std::string	BitcoinExchange::trim(const std::string& value_str) {
	size_t	start = value_str.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = value_str.find_last_not_of(" \t\r\n");
	return value_str.substr(start, end - start + 1);
}

bool	BitcoinExchange::isValidNumberStr(const std::string& str_value) {
	if (str_value.empty())
		return false;
	size_t i = 0;
	if (str_value[0] == '+' || str_value[0] == '-') {
		i = 1;
		if (str_value.length() == 1)
			return false;
	}
	bool	dot = false;
	bool	digits = false;
	for (; i < str_value.length(); ++i) {
		if (str_value[i] == '.') {
			if (dot)
				return false;
			dot = true;
		} else if (std::isdigit(str_value[i])) {
			digits = true;
		} else 
			return false;
	}
	return digits;
}

void	BitcoinExchange::parse_input(const std::string& input) {
	std::ifstream input_file(input.c_str());
	if (!input_file)
		throw ErrorOpeningThisFile();
	std::string	line;
	getline(input_file, line);
	while (getline(input_file, line)) {
		size_t sep = line.find('|');
		if (sep != std::string::npos) {
			std::string date = trim(line.substr(0, sep));
			if (!isValidDate(date)) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			std::string	valueStr = trim(line.substr(sep + 1));
			if (!isValidNumberStr(valueStr)) {
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			double	value = std::atof(valueStr.c_str());
			if (!isValidValue(value)) {
				if (value > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
					std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << value * static_cast<double>(get_exchange_value(date)) << std::endl;
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
	return;
}

bool	BitcoinExchange::isAllDigits(const std::string& str) {
	std::string::const_iterator	it;
	for (it = str.begin(); it != str.end(); ++it) {
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return false;	
	}
	return true;
}

bool	BitcoinExchange::isValidDate(const std::string& date) {

	if (date.length() != 10)
		return false;
	size_t	sep_y = date.find('-');
	std::string	year = date.substr(0, sep_y);
	if (year.length() != 4 || !isAllDigits(year) || year > "2025" || year < "2009")
		return false;
	std::string _date = date.substr(sep_y + 1, date.length());
	size_t	sep_m = _date.find('-');
	std::string	month = _date.substr(0, sep_m);
	if (month.length() != 2 || !isAllDigits(month) || month < "01" || month > "12")
		return false;
	std::string day = _date.substr(sep_m + 1, date.length());
	if (day.length() != 2 || !isAllDigits(day) || day < "01" || day > "31")
		return false;
	if (month == "02" && day == "29") {
		int y = std::atoi(year.c_str());
        if (!( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ))
            return false;
	}
	if ((month == "02" && day > "29") || ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30"))
		return false;
	return true;
}
