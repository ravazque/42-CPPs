/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:27:19 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:14:49 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED__
# define __FIXED__

# include <iostream>
# include <cmath>

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

	float	toFloat(void)const;
	int		toInt(void)const;
	int		getRawBits(void)const;
	void	setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);

#endif
