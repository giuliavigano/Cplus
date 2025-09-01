/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:52 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:52:53 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	findArea(Point const& a, Point const& b, Point const& c) {
	Fixed	area = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY()));
	if (area < 0)
		area = area * Fixed(-1);
	return area / Fixed (2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = findArea(a, b, c);
	if (areaABC == Fixed(0))
		return false;

	Fixed areaPAB = findArea(point, a , b);
	Fixed areaPBC = findArea(point, b, c);
	Fixed areaPCA = findArea(point, c, a);
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0))
		return false;
	return (areaPAB + areaPBC + areaPCA == areaABC);
}
