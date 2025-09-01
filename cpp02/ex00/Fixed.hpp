/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:51:01 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:51:02 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& value);
	Fixed &operator=(const Fixed& val);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_fixPoint;
	static const int	_fractionalBits;
};

#endif