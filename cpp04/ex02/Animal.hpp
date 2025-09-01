/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:14:04 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:05 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>
#include <iostream>

class Animal {
public:
	Animal(void);
	Animal(const std::string& type);
	Animal(const Animal& value);
	Animal &operator=(const Animal& val);
	virtual ~Animal(void);
	
	std::string	getType(void) const;
	virtual void makeSound() const = 0;
protected:
	std::string type;
};

#endif