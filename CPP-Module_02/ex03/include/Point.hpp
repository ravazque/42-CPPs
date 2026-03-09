/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/03/09 19:38:59 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

# include "Fixed.hpp"

class Point
{
	private:

		Fixed const	_x;
		Fixed const	_y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point &copy);

		~Point();

		Point &operator=(const Point &src);

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
