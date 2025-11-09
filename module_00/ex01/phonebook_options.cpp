/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_options.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:54:09 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/09 02:21:23 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phoneBook::phoneBook() : max_contacts(8), current_nb(0), nb_contacts(0)
{
}

phoneBook::~phoneBook()
{
}

bool	phoneBook::get_input(string &input, const string &prompt)
{
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			std::cout << std::endl << "Fast exit detected. Exiting..." << std::endl;
			return (false);
		}
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Please try again." << std::endl;
			continue;
		}
		return (true);
	}
}

void	phoneBook::add_contact()
{
	string	name;
	string	last;
	string	nick;
	string	phone;
	string	secret;

	if (this->current_nb == 8)
		this->current_nb = 0;
	system("clear");
	if (!get_input(name, "Type the first name: "))
		exit(0);
	if (!get_input(last, "Type the last name: "))
		exit(0);
	if (!get_input(nick, "Type the nickname: "))
		exit(0);
	if (!get_input(phone, "Type the phone-number: "))
		exit(0);
	if (!get_input(secret, "Type the darkest secret: "))
		exit(0);

	system("clear");

	this->array[this->current_nb].setName(name);
	this->array[this->current_nb].setLast(last);
	this->array[this->current_nb].setNick(nick);
	this->array[this->current_nb].setPhone(phone);
	this->array[this->current_nb].setSecret(secret);

	this->current_nb++;

	if (nb_contacts < 8)
		nb_contacts++;
}
