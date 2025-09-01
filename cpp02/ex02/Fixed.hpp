/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:20 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:52:21 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& value);
	Fixed &operator=(const Fixed& val);
	~Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const point);
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	static Fixed& min(Fixed& value1, Fixed& value2);
	static const Fixed& min(const Fixed& value1, const Fixed& value2);
	static Fixed& max(Fixed& value1, Fixed& value2);
	static const Fixed& max(const Fixed& value1, const Fixed& value2);
	
private:
	int					_fixedPoint;
	static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif