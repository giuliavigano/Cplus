/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:53:01 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:53:02 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float n1, const float n2) : x(n1), y(n2) {}

Point::Point(const Point& value) : x(value.x), y(value.y) {}

Point&	Point::operator=(const Point& val) {
	(void)val;
	return *this;
}

Point::~Point(void) {}

Fixed	Point::getX(void) const {
	return this->x;
}

Fixed	Point::getY(void) const {
	return this->y;
}
