#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "We need only one input: file.txt !" << std::endl;
		return 1;
	}
	std::cout << "\n=== TEST INPUT FILE.TXT ===" << std::endl;
	BitcoinExchange btc;
	btc.loadDatabase();
	try {
		btc.parse_input(argv[1]);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}