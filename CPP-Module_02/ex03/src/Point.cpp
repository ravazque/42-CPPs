/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/03/09 19:39:07 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
}

Point::~Point()
{
}

Point	&Point::operator=(const Point &src)
{
	(void)src;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
