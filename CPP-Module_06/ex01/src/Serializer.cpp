/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:05:48 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/13 14:17:53 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &src) { (void)src; }

Serializer::~Serializer(void) {}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
