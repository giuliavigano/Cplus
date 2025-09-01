/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:03:08 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:03:09 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default") {
	this->name = "fragDefault";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "Default FragTrap constructor called for: " << this->name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap string constructor called for: " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& value) : ClapTrap(value.name) {
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	std::cout << "FragTrap copy constructor called for: " << this->name << std::endl;
} 

FragTrap&	FragTrap::operator=(const FragTrap& val) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &val) {
		this->name = val.name;
		this->hitPoints = val.hitPoints;
		this->energyPoints = val.energyPoints;
		this->attackDamage = val.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called for: " << this->name << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "FragTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (this->hitPoints == 0) {
		std::cout << "FragTrap " << this->name << " cannot take action." << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " requests a positive high five!" << std::endl; 
}
