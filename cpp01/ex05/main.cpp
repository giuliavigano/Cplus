/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:31:04 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:31:05 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\n[ INFO ]" << std::endl;
	harl.complain("INFO");
	std::cout << "\n[ WARNING ]" << std::endl;
	harl.complain("WARNING");
	std::cout << "\n[ ERROR ]" << std::endl;
	harl.complain("ERROR");
	std::cout << "\n[ UNKNOWN ]" << std::endl;
	harl.complain("UNKNOWN");
	return 0;
}