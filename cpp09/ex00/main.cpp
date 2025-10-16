/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:21:22 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/16 16:21:23 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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