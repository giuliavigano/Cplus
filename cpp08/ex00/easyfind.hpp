/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:41:33 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/14 16:37:33 by giuliaviga       ###   ########.fr       */
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
typename T::iterator	easyfind(T& container, int value) {
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it != container.end())
		return it;
	else
		throw NotInThereException();
}

// template<typename T>
// typename T::iterator easyfind(T& container, int value) {
// 	for (typename T::iterator i = container.begin();
// 		i != container.end(); ++i) {
// 			if (*i == value )
// 				return i;
// 		}
// 	throw NotInThereException();
// }


#endif