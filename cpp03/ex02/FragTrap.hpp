/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:02:33 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:02:34 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& value);
	FragTrap &operator=(const FragTrap& val);
	~FragTrap(void);
	void	highFivesGuys(void);
	void	attack(const std::string& target);
private:
};

#endif