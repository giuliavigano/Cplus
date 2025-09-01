/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:02:42 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:02:43 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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

	std::cout << "\n=== FRAGTRAP TESTS ===" << std::endl;

	std::cout << "\nTEST 19: FragTrap Default Constructor:" << std::endl;
	FragTrap defaultFrag;

	std::cout << "\nTEST 20: FragTrap Parametric Constructor:" << std::endl;
	FragTrap namedFrag("Destroyer");

	std::cout << "\nTEST 21: FragTrap Copy Constructor:" << std::endl;
	FragTrap copiedFrag(namedFrag);

	std::cout << "\nTEST 22: FragTrap Assignment Operator:" << std::endl;
	FragTrap assignedFrag;
	assignedFrag = namedFrag;

	std::cout << "\nTEST 23: FragTrap Attack Function:" << std::endl;
	namedFrag.attack("Enemy1");
	namedFrag.attack("Enemy2");
	namedFrag.attack("Enemy3");

	std::cout << "\nTEST 24: FragTrap High Fives Function:" << std::endl;
	namedFrag.highFivesGuys();
	copiedFrag.highFivesGuys();

	std::cout << "\nTEST 25: FragTrap Inherited Functions:" << std::endl;
	namedFrag.takeDamage(40);
	namedFrag.beRepaired(20);
	namedFrag.takeDamage(30);

	std::cout << "\nTEST 26: FragTrap Values Test:" << std::endl;
	FragTrap valueFragTest("FragValueBot");
	for (int i = 1; i <= 101; i++) {
		std::cout << "action number " << i << " : ";
		valueFragTest.attack("EnergyTest");
	}

	std::cout << "\nTEST 27: FragTrap Death Test:" << std::endl;
	FragTrap fragDeathTest("FragDeathBot");
	fragDeathTest.takeDamage(100);
	fragDeathTest.attack("Someone");
	fragDeathTest.highFivesGuys();
	fragDeathTest.beRepaired(10);

	return 0;
}
