/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:30:07 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 12:30:08 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& value);
	Cat &operator=(const Cat& val);
	~Cat(void);
	void makeSound() const;
private:
};

#endif