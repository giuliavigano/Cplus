/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:53:04 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:53:04 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float n1, const float n2);
	Point(const Point& value);
	Point &operator=(const Point& val);
	~Point(void);
	Fixed getX(void) const;
	Fixed getY(void) const;
private:
	Fixed const x;
	Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif