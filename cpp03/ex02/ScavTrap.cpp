/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:02:48 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:02:48 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default") {
	this->name = "scavDefault";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Default ScavTrap constructor called for: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap string constructor called for: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& value) : ClapTrap(value.name) {
	this->name = value.name;
	this->hitPoints = value.hitPoints;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	std::cout << "ScavTrap copy constructor called for: " << this->name << std::endl;
} 

ScavTrap&	ScavTrap::operator=(const ScavTrap& val) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &val) {
		this->name = val.name;
		this->hitPoints = val.hitPoints;
		this->energyPoints = val.energyPoints;
		this->attackDamage = val.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called for: " << this->name << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	if (this->energyPoints == 0) {
		std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() {
	if (this->hitPoints == 0) {
		std::cout << "ScavTrap " << this->name << " cannot take action." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode. Hit points remaining: "
			  << this->hitPoints << std::endl; 
}

