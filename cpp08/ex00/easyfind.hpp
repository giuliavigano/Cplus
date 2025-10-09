/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:41:33 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/09 14:41:34 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <vector>
#include <deque>
#include <list>
#include <exception>

class NotInThereException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Occurrence of parameter not found";
	}
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {
	for (typename T::iterator i = container.begin();
		i != container.end(); ++i) {
			if (*i == value )
				return i;
		}
	throw NotInThereException();
}



#endif