/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:11:51 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:11:52 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new(Brain);
}

Dog::Dog(const Dog& value) : Animal(value.type) {
	std::cout << "Dog copy constuctor called" << std::endl;
	this->brain = new Brain(*value.brain);
}

Dog& Dog::operator=(const Dog& val) {
	if (this != &val) {
		Animal::operator=(val);
		delete this->brain;
		this->brain = new Brain(*val.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}

Brain*	Dog::getBrain() const {
	return this->brain;
}
