/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 01:29:18 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Fixed
{
	private:
	
		int					_fp_value;
		static const int	_fract_bits;

	public:

		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed &operator=(const Fixed &src);

		int getRawBits(void)const;
		void setRawBits(int const raw);
};
