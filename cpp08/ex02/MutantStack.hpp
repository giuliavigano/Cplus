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

	iterator	end();
	iterator	begin();
	const_iterator	end() const;
	const_iterator	begin() const;
private:
};

#include "MutantStack.tpp"

#endif