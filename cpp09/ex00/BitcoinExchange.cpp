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
	if (value < 0 || !std::isdigit(value)){
		throw NotAValidNumber();
		return false;
	}
	else if (value > 1000) {
		throw NumberTooLarge();
		return false;
	}
	else
		return true;
}

void	BitcoinExchange::parse_input(const std::string& input) {
	std::ifstream input_file(input);
	if (!input_file)
		throw ErrorOpeningThisFile();
	std::string	line;
	getline(input_file, line);
	while (getline(input_file, line)) {
		size_t sep = line.find('|');
		std::string date = line.substr(0, sep);
		float value = std::stof(line.substr(sep + 1, line.length()));
		try {
			isValidDate(date);
		} catch (const std::exception& e) {
			throw NotAValidDate();
			break;
		}
		if (!isValidValue(static_cast<double>(value)))
			break;
	}
	return;
}

// use in a try/catch (std::exception) and use your NotAValidDate exception !
bool	BitcoinExchange::isValidDate(const std::string& date) {

	if (date.length() != 10)
		return false;
	size_t	sep_y = date.find('-');
	std::string	year = date.substr(0, sep_y);
	if (year.length() != 4 || !std::all_of(year.begin(), year.end(), [](char c){ return std::isdigit(static_cast<unsigned char>(c)); }) || year > "2025" || year < "2009")
		return false;
	std::string _date = date.substr(sep_y + 1, date.length());
	size_t	sep_m = _date.find('-');
	std::string	month = _date.substr(0, sep_m);
	if (month.length() != 2 || !std::all_of(month.begin(), month.end(), [](char c){ return std::isdigit(static_cast<unsigned char>(c)); }) || month < "01" || month > "12")
		return false;
	std::string day = _date.substr(sep_m + 1, date.length());
	if (day.length() != 2 || !std::all_of(day.begin(), day.end(), [](char c){ return std::isdigit(static_cast<unsigned char>(c)); }) || day < "01" || day > "31")
		return false;
	if (month == "02" && day == "29") {
		int y = std::stoi(year);
        if (!( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ))
            return false;
	}
	if ((month == "02" && day > "29") || ((month == "04" || month == "06" || month == "09" || month == "11") && day > "30"))
		return false;
	return true;
}
