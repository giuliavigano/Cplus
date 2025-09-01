/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:02:20 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:02:20 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "Default constructor called for: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "String constructor called for: " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& value) : name(value.name), hitPoints(value.hitPoints), energyPoints(value.energyPoints), attackDamage(value.attackDamage) {
	std::cout << "Copy constructor called for: " << this->name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& val) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &val) {
		this->name = val.name;
		this->hitPoints = val.hitPoints;
		this->energyPoints = val.energyPoints;
		this->attackDamage = val.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called for: " << this->name << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " cannot take damage." << std::endl;
		return;
	}
	if (amount >= this->hitPoints) {
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " takes this damage: " << amount
				  << ", and dies!!" << std::endl;
		return;
	} else {
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " takes this amount of damage points: " << amount
				  << " Hit points remaining: " << this->hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0) {
		std::cout << "ClapTrap " << this->name << " already died!" << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ClapTrap " << this->name << " cannot repair itself due to lack of energy points!" << std::endl;
		return;
	}
	this->energyPoints--;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for: " << amount
			  << " Hit points. Hit points remaining: " << this->hitPoints << std::endl;
}
