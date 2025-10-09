#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <string>
#include <stack>
#include <deque>
#include <iostream>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
	typename Container::iterator	end();
	typename Container::iterator	begin();
	typename Container::const_iterator	end() const;
	typename Container::const_iterator	begin() const;
private:
};

#include "MutantStack.tpp"

#endif