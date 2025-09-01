/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:32:02 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:07:00 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


int	main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT)";
		if (!std::getline(std::cin, command)) {
			std::cout << "\nEOF detected" << std::endl;
			break;
		}
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}
