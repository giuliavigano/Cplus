/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:14:25 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:25 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& value);
	Dog &operator=(const Dog& val);
	~Dog(void);
	void makeSound() const;
	Brain* getBrain() const;
private:
	Brain* brain;
};

#endif