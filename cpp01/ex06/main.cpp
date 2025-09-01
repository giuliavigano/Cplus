/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:31:33 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:31:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[]) {
	Harl	harl;
	int		i = -1;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc != 2) {
		std::cout << "We need only one level as a parameter." << std::endl;
		return 1;
	}
	std::string level = argv[1];
	for (int j = 0; j < 4; j++) {
		if (level == levels[j]) {
			i = j;
			break;
		}
	}
	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			/* fall through */
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			/* fall through */
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			/* fall through */
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ UNKNOWN ]" << std::endl;
			harl.complain("UNKNOWN");
	}
	return 0;
}