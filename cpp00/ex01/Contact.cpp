/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:31:46 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:07:46 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

std::string Contact::truncate(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void 	Contact::getData() {
	std::string input;

	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected" << std::endl;
		exit (0);
	}
	while (input.empty()){
		std::cout << "First name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->firstName = input;
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected" << std::endl;
		exit(0);
	}
	while (input.empty()){
		std::cout << "Last name cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->lastName = input;
	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected" << std::endl;
		exit(0);
	}
	while (input.empty()){
		std::cout << "Nickname cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->nickName = input;
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected" << std::endl;
		exit(0);
	}
	while (input.empty()){
		std::cout << "Phone number cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->phoneNumber = input;
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, input)) {
		std::cout << "\nEOF detected" << std::endl;
		exit(0);
	}
	while (input.empty()){
		std::cout << "Darkest secret cannot be empty. Try again: ";
		std::getline(std::cin, input);
	}
	this->darkestSecret = input;
}

void	Contact::displayTruncateIndex(int index) {
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << truncate(firstName) << "|"
			  << std::setw(10) << truncate(lastName) << "|"
			  << std::setw(10) << truncate(nickName) << std::endl;
}

void	Contact::printContactDetail() {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: "	<< lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

