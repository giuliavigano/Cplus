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
			float	value = std::stof(line.substr(com + 1));
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
	auto	it = database.lower_bound(date);
	if (it == database.begin())
		return "";
	--it;
	return it->first;
}

// GESTISCI WHITESPACE QUANDO VAI A DICHIARARE DATE E VALUE
void	BitcoinExchange::parse_input(const std::string& input) {
	std::ifstream input_file(input);
	if (!input_file)
		throw ErrorOpeningThisFile();
	std::string	line;
	getline(input_file, line);
	while (getline(input_file, line)) {
		size_t sep = line.find('|');
		if (sep != std::string::npos) {
			std::string date = line.substr(0, sep);
			float value = std::stof(line.substr(sep + 1, line.length())); //DA TESTARE CON TRY CATCH PER STOF!
			if (!isValidDate(date)) {
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (!isValidValue(static_cast<double>(value))) {
				if (value > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
					std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			std::cout << date << " => " << value << " = " << value * get_exchange_value(date) << std::endl;
		} else {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
	}
	return;
}

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
