#include "MutantStack.hpp"

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
