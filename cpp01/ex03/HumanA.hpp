/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:29:45 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:29:45 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA {
public:
	void	attack();
	HumanA(std::string name, Weapon& weapon);
private:
	std::string name;
	Weapon& weapon;
};

#endif
