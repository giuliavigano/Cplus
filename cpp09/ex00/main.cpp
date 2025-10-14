#include "BitcoinExchange.hpp"

std::map<std::string, float>	read_datacsv() {
	std::map<std::string, float> exchangeValue;
	std::ifstream dataFile("data.csv");
	std::string	line;
	getline(dataFile, line);
	while (getline(dataFile, line)) {
		size_t	com = line.find('.');
		if (com != std::string::npos) {
			std::string date = line.substr(0, com);
			float	value = std::stof(line.substr(com + 1));
			exchangeValue[date] = value;
		}
	}
	return exchangeValue;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "We need only one input: file .txt !" << std::endl;
		return 1;
	}
	try {
		std::ifstream input_file(argv[1]);
		if (!input_file.is_open())
			throw ErrorOpeningThisFile();
	} catch (const ErrorOpeningThisFile& e) {
		std::cout << e.what() << std::endl;
	}
	std::map<std::string, float> date_csv = read_datacsv();
	std::string	line;
	std::ifstream file(argv[1]);
	getline(file, line);
	while (getline(file, line)) {
		size_t com = line.find('|');
		if (com != std::string::npos) {
		}
	}
	return 0;
}