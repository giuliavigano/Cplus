/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:28:17 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:28:17 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <string>

class Zombie {
public:
	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
private:
	std::string name;
};

#endif