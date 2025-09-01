/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:14:07 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:08 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const std::string& idea) {
	std::cout << "Brain string constructor called" << std::endl;
	(void)idea;
}

Brain::Brain(const Brain& value) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = value.ideas[i];
	}
}

Brain&	Brain::operator=(const Brain& val) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &val) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = val.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}
