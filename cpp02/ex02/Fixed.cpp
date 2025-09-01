/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:17 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:52:18 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}

Fixed::Fixed(void) : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& value) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = value.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& val) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &val)
		this->_fixedPoint = val.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = n << _fractionalBits;/*n * 256*/
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(f * (1 << _fractionalBits));/*f * 256*/
}

int		Fixed::getRawBits(void) const {
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const point) {
	this->_fixedPoint = point;
}

int		Fixed::toInt(void) const {
	return _fixedPoint >> _fractionalBits;
}

float	Fixed::toFloat(void) const {
	return (float)_fixedPoint / (float)(1 << _fractionalBits);
}

Fixed& Fixed::operator++() {
	_fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	_fixedPoint++;
	return tmp;
}

Fixed&	Fixed::operator--() {
	_fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	_fixedPoint--;
	return tmp;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;
	result.setRawBits(this->_fixedPoint + other._fixedPoint);
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	result;
	result.setRawBits(this->_fixedPoint - other._fixedPoint);
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;
	result.setRawBits((this->_fixedPoint * other._fixedPoint) >> _fractionalBits);
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed	result;
	result.setRawBits(this->_fixedPoint << _fractionalBits / other._fixedPoint);
	return result;
}
Fixed&	Fixed::min(Fixed& value1, Fixed& value2) {
	return (value1 < value2) ? value1 : value2;
}

const Fixed&	Fixed::min(const Fixed& value1, const Fixed& value2) {
	return (value1 < value2) ? value1 : value2;
}

Fixed&	Fixed::max(Fixed& value1, Fixed& value2) {
	return (value1 > value2) ? value1 : value2;
}

const Fixed&	Fixed::max(const Fixed& value1, const Fixed& value2) {
	return (value1 > value2) ? value1 : value2;
}

bool	Fixed::operator>(const Fixed& other) const {
	return _fixedPoint > other._fixedPoint;
}

bool	Fixed::operator<(const Fixed& other) const {
	return _fixedPoint < other._fixedPoint;
}

bool	Fixed::operator>=(const Fixed& other) const {
	return _fixedPoint >= other._fixedPoint;
}

bool	Fixed::operator<=(const Fixed& other) const {
	return _fixedPoint <= other._fixedPoint;
}

bool	Fixed::operator==(const Fixed& other) const {
	return _fixedPoint == other._fixedPoint;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return _fixedPoint != other._fixedPoint;
}

