/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:50:59 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:50:59 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& value) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixPoint = value.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& val) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &val)
		this->_fixPoint = val.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixPoint;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixPoint = raw;
}
