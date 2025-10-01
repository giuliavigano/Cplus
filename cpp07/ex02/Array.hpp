#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <string>
#include <exception>
#include <iostream>

template<typename N>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array<N>& value);
	Array<N>&	operator=(const Array<N>& val);
	~Array();

	N&			operator[](unsigned int index);
	const N&	operator[](unsigned int index) const;

	unsigned int	size() const;

private:
	N* 	elements;
	unsigned int	_size;
};

template<typename N>
Array<N>::Array() : elements(NULL), _size(0) {
	std::cout << "Default constructor called" << std::endl;
}

template<typename N>
Array<N>::Array(unsigned int n) : _size(n) {
	if (n == 0)
		elements = NULL;
	else
		elements = new N[n];
	std::cout << "Parametric constructor called" << std::endl; 
}

template<typename N>
Array<N>::Array(const Array<N>& value) {
	this->_size = value._size;
	if (_size == 0)
		elements = NULL;
	else {
		elements = new N[_size];
		for (unsigned int i = 0; i < _size; i++)
			elements[i] = value.elements[i];
	}
	std::cout << "Copy constructor called" << std::endl;
}

template<typename N>
Array<N>&	Array<N>::operator=(const Array<N>& val) {
	if (this != &val) {
		delete[] elements;
		_size = val._size;
		if (_size == 0)
			elements = NULL;
		else {
			elements = new N[_size];
			for (unsigned int i = 0; i < _size; i++)
				elements[i] = val.elements[i];
		}
	}
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

template<typename N>
Array<N>::~Array() {
	delete[] elements;
	std::cout << "Default destructor called" << std::endl;
}

template<typename N>
N&	Array<N>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::exception();
	return elements[index];
}

template<typename N>
const N&	Array<N>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::exception();
	return elements[index];
}

template<typename N>
unsigned int	Array<N>::size() const {
	return this->_size;
}

#endif