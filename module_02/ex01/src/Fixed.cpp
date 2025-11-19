/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:27:17 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 01:40:51 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed(): _fp_value(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int Constructor called" << std::endl;
	this->_fp_value = input << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignmet operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();

	return *this;
}

float	Fixed::toFloat(void)const
{
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

int	Fixed::getRawBits(void)const
{
	return (this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
