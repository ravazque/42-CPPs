/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/03/09 19:39:03 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed	cross_product(Point const p1, Point const p2, Point const p3)
{
	return (Fixed((p2.getX() - p1.getX()) * (p3.getY() - p1.getY())
		- (p2.getY() - p1.getY()) * (p3.getX() - p1.getX())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross_product(a, b, point);
	Fixed d2 = cross_product(b, c, point);
	Fixed d3 = cross_product(c, a, point);

	bool has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	bool has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	return (!(has_neg && has_pos));
}
