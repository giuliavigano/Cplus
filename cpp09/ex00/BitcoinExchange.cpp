#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : database() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& value) : database(value.database) {}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& val) {
    if (this != &val) {
        this->database = val.database
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool    BitcoinExchange::isValidDate(const std::string& date) {
    for (size_t i = 0; i < date.length(); i++) {
        size_t	sep = date.find('-');
    }
}

double  BitcoinExchange::isValidValue(double value) {
}