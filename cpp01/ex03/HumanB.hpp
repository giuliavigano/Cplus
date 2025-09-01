/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:29:50 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:29:51 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
public:
	void	attack();
	void	setWeapon(Weapon& weapon);
	HumanB(std::string name);
private:
	std::string name;
	Weapon* weapon;
};

#endif