/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_contact.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:06:45 by babreton          #+#    #+#             */
/*   Updated: 2025/11/19 13:27:09 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

contact::contact()
{
}

contact::~contact()
{
}

void	contact::setName(string name)
{
	this->name = name;
}

void	contact::setLast(string last)
{
	this->last = last;
}

void	contact::setNick(string nick)
{
	this->nick = nick;
}

void	contact::setPhone(string phone)
{
	this->phone = phone;
}

void	contact::setSecret(string secret)
{
	this->secret = secret;
}

string	contact::getName() const
{
	return this->name;
}

string contact::getLast() const
{
	return this->last;
}

string contact::getNick() const
{
	return this->nick;
}

string contact::getPhone() const
{
	return this->phone;
}

string	contact::getSecret() const
{
	return this->secret;
}
