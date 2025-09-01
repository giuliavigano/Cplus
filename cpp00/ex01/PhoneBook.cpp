/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:32:06 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 10:32:07 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iomanip>

PhoneBook::PhoneBook() {
	contactCount = 0;
	nextIndex = 0;
}

void PhoneBook::addContact() {
	contacts[nextIndex].getData();

	if (contactCount < 8)
		contactCount++;
	
	nextIndex = (nextIndex + 1) % 8;
}

void PhoneBook::displayContact(int index) {
		contacts[index].printContactDetail();
}

void PhoneBook::searchContact() {
	if (contactCount == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < contactCount; i++)
		contacts[i].displayTruncateIndex(i);
	
	std::cout << "Enter the index of the contact to display: ";
	int index;
	if (!(std::cin >> index) || index < 0 || index >= contactCount) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input: not a number." << std::endl;
		return;
	}
	std::cin.ignore();
	displayContact(index);
}