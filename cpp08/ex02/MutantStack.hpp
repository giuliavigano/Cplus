/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:42:24 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/09 14:42:24 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <string>
#include <stack>
#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator	iterator;
	typedef typename Container::const_iterator	const_iterator;

	MutantStack();
	MutantStack(const MutantStack<T, Container>& value);
	MutantStack<T, Container> &operator=(const MutantStack<T, Container>& val);
	~MutantStack();

	iterator	begin();
	iterator	end();
	const_iterator	begin() const;
	const_iterator	end() const;
private:
};

#include "MutantStack.tpp"

#endif