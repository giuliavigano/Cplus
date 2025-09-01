/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:14:15 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:15 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& value);
	Cat &operator=(const Cat& val);
	~Cat(void);
	void makeSound() const;
	Brain* getBrain() const;
private:
	Brain* brain;
};

#endif