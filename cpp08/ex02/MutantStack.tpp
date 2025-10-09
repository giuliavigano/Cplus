/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:42:28 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/09 14:42:28 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& value) : std::stack<T, Container>(value) {}

template<typename T, typename Container>
MutantStack<T, Container>&  MutantStack<T, Container>::operator=(const MutantStack<T, Container>& val) {
    if (this != &val)
        std::stack<T, Container>::operator=(val);
    return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack () {}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end() {
    return this->c.end();
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin() {
    return this->c.begin();
}

template<typename T, typename Container>
typename Container::const_iterator    MutantStack<T, Container>::end() const {
    typename Container::const_iterator  it = this->c.end();
    return it;
}

template<typename T, typename Container>
typename Container::const_iterator    MutantStack<T, Container>::begin() const {
    typename Container::const_iterator  it = this->c.begin();
    return it;
}
