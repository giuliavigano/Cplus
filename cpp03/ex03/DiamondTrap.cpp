/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:03:02 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:03:02 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), name("default") {
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap default constructor called for: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
	std::cout << "DiamondTrap string constructor called for: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& value) : ClapTrap(value.name + "_clap_name"), FragTrap(value), ScavTrap(value), name(value.name) {
	ClapTrap::name = this->name + "_clap_name";
	this->hitPoints = value.hitPoints;
	this->energyPoints = value.energyPoints;
	this->attackDamage = value.attackDamage;
	std::cout << "DiamondTrap copy constructor called for: " << this->name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& val) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &val) {
		this->name = val.name;
		ClapTrap::name = val.name + "_clap_name";
		this->hitPoints = val.hitPoints;
		this->energyPoints = val.energyPoints;
		this->attackDamage = val.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called for: " << this->name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	if (this->hitPoints == 0) {
		std::cout << "DiamondTrap " << this->name << " cannot take action." << std::endl;
		return;
	}
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}