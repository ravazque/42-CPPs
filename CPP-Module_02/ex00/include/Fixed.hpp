/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 20:24:42 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

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

	int		getRawBits(void)const;
	void	setRawBits(int const raw);
};

#endif
