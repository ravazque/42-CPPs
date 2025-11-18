/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:21:24 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/18 21:24:23 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

class Fixed
{
	public:

		Fixed();
		Fixed(Fixed const &src);
		~Fixed();

		Fixed&	operator=(Fixed const &rSym);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					value;
		static const int	bits = 8;
};

#endif

