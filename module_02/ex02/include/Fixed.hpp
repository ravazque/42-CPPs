/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:27:19 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:34:57 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
# define __FIXED__

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int					_fp_value;
		static const int	_fract_bits;

	public:

		Fixed();
		Fixed(const int input);
		Fixed(const float input);
		Fixed(const Fixed& copy);

		~Fixed();

		Fixed &operator=(const Fixed &src);

	bool	operator>(Fixed fixed)const;
	bool	operator<(Fixed fixed)const;
	bool	operator>=(Fixed fixed)const;
	bool	operator<=(Fixed fixed)const;
	bool	operator==(Fixed fixed)const;
	bool	operator!=(Fixed fixed)const;

	float	operator+(Fixed fixed)const;
	float	operator-(Fixed fixed)const;
	float	operator*(Fixed fixed)const;
	float	operator/(Fixed fixed)const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	float	toFloat(void)const;
	int		toInt(void)const;
	
	static Fixed &min(Fixed &first, Fixed &second);
	static const Fixed &min(Fixed const &first, Fixed const &second);

	static Fixed &max(Fixed &first, Fixed &second);
	static const Fixed &max(Fixed const &first, const Fixed &second);

	int		getRawBits(void)const;
	void	setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
