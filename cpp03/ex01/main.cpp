/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:02:10 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:02:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
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

	std::cout << "\n=== SCAVTRAP TESTS ===" << std::endl;

	std::cout << "\nTEST 10: ScavTrap Default Constructor:" << std::endl;
	ScavTrap defaultScav;

	std::cout << "\nTEST 11: ScavTrap Parametric Constructor:" << std::endl;
	ScavTrap namedScav("Warrior");

	std::cout << "\nTEST 12: ScavTrap Copy Constructor:" << std::endl;
	ScavTrap copiedScav(namedScav);

	std::cout << "\nTEST 13: ScavTrap Assignment Operator:" << std::endl;
	ScavTrap assignedScav;
	assignedScav = namedScav;

	std::cout << "\nTEST 14: ScavTrap Attack Function:" << std::endl;
	namedScav.attack("Enemy1");
	namedScav.attack("Enemy2");
	namedScav.attack("Enemy3");

	std::cout << "\nTEST 15: ScavTrap Guard Gate Function:" << std::endl;
	namedScav.guardGate();
	copiedScav.guardGate();

	std::cout << "\nTEST 16: ScavTrap Inherited Functions:" << std::endl;
	namedScav.takeDamage(30);
	namedScav.beRepaired(15);
	namedScav.takeDamage(50);

	std::cout << "\nTEST 17: ScavTrap Values Test:" << std::endl;
	ScavTrap valueTest("ValueBot");
	for (int i = 1; i <= 51; i++) {
		std::cout << "action number " << i << " : ";
		valueTest.attack("EnergyTest");
	}

	std::cout << "\nTEST 18: ScavTrap Death Test:" << std::endl;
	ScavTrap scavDeathTest("ScavDeathBot");
	scavDeathTest.takeDamage(100);
	scavDeathTest.attack("Someone");
	scavDeathTest.guardGate();
	scavDeathTest.beRepaired(10);

	return 0;
}
