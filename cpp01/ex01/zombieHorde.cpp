/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:28:19 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:28:20 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return horde;
}
