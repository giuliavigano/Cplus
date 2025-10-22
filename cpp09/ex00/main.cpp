/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:21:22 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/22 12:06:56 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::cout << "\n=== TEST INPUT FILE.TXT ===" << std::endl;
	BitcoinExchange btc;
	btc.loadDatabase();
	btc.parse_input(argv[1]);
	return 0;
}