/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:01:42 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:19:15 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

	std::cout << "\n=== CLAPTRAP TESTS ===" << std::endl;

	std::cout << "\nTEST 1: ClapTrap Default Constructor:" << std::endl;
	ClapTrap robot1;

	std::cout << "\nTEST 2: ClapTrap Parametric Constructor:" << std::endl;
	ClapTrap robot2("ClapBot");

	std::cout << "\nTEST 3: ClapTrap Copy Constructor:" << std::endl;
	ClapTrap robot3(robot2);

	std::cout << "\nTEST 4: ClapTrap Assignment Operator:" << std::endl;
	ClapTrap robot4;
	robot4 = robot2;

	std::cout << "\nTEST 5: ClapTrap Attack Function:" << std::endl;
	robot2.attack("Enemy1");
	robot2.attack("Enemy2");

	std::cout << "\nTEST 6: ClapTrap Take Damage:" << std::endl;
	robot2.takeDamage(3);
	robot2.takeDamage(5);

	std::cout << "\nTEST 7: ClapTrap Repair:" << std::endl;
	robot2.beRepaired(4);
	robot2.beRepaired(2);

	std::cout << "\nTEST 8: ClapTrap Energy Limit:" << std::endl;
	ClapTrap energyTest("EnergyBot");
	for (int i = 1; i <= 12; i++) {
		std::cout << "action number " << i << " : ";
		energyTest.attack("Target");
	}

	std::cout << "\nTEST 9: ClapTrap Death Test:" << std::endl;
	ClapTrap deathTest("DeathBot");
	deathTest.takeDamage(15);
	deathTest.attack("Someone");
	deathTest.beRepaired(5);
	
	return 0;
}
