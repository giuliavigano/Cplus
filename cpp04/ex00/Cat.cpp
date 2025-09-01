/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:30:05 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:30:06 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& value) : Animal(value.type) {
	std::cout << "Cat copy constuctor called" << std::endl;
}

Cat& Cat::operator=(const Cat& val) {
	if (this != &val)
		Animal::operator=(val);
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}