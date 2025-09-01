/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:28:10 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:28:10 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie*	zombieHorde(int N, std::string name);

int	main(void) {
	Zombie* horde = zombieHorde(10, "Horde");
	
	for (int i = 0; i < 10; ++i)
		horde[i].announce();
	delete[] horde;
}