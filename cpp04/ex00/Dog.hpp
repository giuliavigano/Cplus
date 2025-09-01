/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:30:12 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:30:13 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& value);
	Dog &operator=(const Dog& val);
	~Dog(void);
	void makeSound() const;
private:
};

#endif