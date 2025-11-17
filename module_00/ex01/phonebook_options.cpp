/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_options.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:54:09 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/17 21:17:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phoneBook::phoneBook() : max_contacts(8), number(0), contacts(0)
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

	if (this->number == max_contacts)
		this->number = 0;
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

	this->book[this->number].setName(name);
	this->book[this->number].setLast(last);
	this->book[this->number].setNick(nick);
	this->book[this->number].setPhone(phone);
	this->book[this->number].setSecret(secret);

	this->number++;

	if (contacts < max_contacts)
		contacts++;
}

void	phoneBook::search_contact()
{
	string	name;
	string	last;
	string	nick;
	string	phone;
	string	secret;
	string	ret;
	int	i = 0;
	int	index;

	system("clear");

	if (this->number == 0)
	{
		std::cout << "No contact avalaible!" << std::endl;
		return;
	}

	std::cout << "―――――――――――――――――――――――――――――――――――――――――――――――――――――" << std::endl;
	std::cout << "│" << std::setw(11) << "Index" << " │";
	std::cout << std::setw(11) << "Firstname" << " │";
	std::cout << std::setw(11) << "Lastname" << " │";
	std::cout << std::setw(11) << "Nickname" << " │" << std::endl;
	std::cout << "―――――――――――――――――――――――――――――――――――――――――――――――――――――" << std::endl;

	while (i < contacts)
	{
		std::cout << "│" << std::setw(11) << (i + 1) << " │";

		name = this->book[i].getName();
		last = this->book[i].getLast();
		nick = this->book[i].getNick();
		phone = this->book[i].getPhone();
		secret = this->book[i].getSecret();

		if (name.length() > 10)
			name = name.substr(0, 9) + ".";

		if (last.length() > 10)
			last = last.substr(0, 9) + ".";

		if (nick.length() > 10)
			nick = nick.substr(0, 9) + ".";

		std::cout << std::setw(11) << name << " │";
		std::cout << std::setw(11) << last << " │";
		std::cout << std::setw(11) << nick << " │" << std::endl;

		i++;
	}
	std::cout << "―――――――――――――――――――――――――――――――――――――――――――――――――――――" << std::endl;

	std::cout << std::endl << "Type a contact's index to obtain personal informations: ";
	if (!std::getline(std::cin, ret) || std::cin.eof())
	{
		std::cout << std::endl << "Fast exit detected. Exiting..." << std::endl;
		exit(0);
	}

	if (ret.empty())
	{
		std::cout << "Index cannot be empty! Returning to the main menu." << std::endl; sleep(1); system("clear");
		return;
	}

	bool is_valid = true;
	for (size_t j = 0; j < ret.length(); j++)
	{
		if (!isdigit(ret[j]))
		{
			is_valid = false;
			break;
		}
	}

	if (!is_valid)
	{
		std::cout << "Please enter a valid digit! Returning to the main menu." << std::endl; sleep(1); system("clear");
		return;
	}

	index = atoi(ret.c_str());

	if (index < 1 || index > max_contacts)
	{
		std::cout << "Index must be between 1 and 8! Returning to the main menu." << std::endl; sleep(1); system("clear");
		return;
	}

	if (index > this->contacts)
	{
		std::cout << "No contact found! Returning to the main menu." << std::endl; sleep(1); system("clear");
		return;
	}

	index--;

	std::cout << "Name: " << this->book[index].getName() << std::endl;
	std::cout << "Lastname: " << this->book[index].getLast() << std::endl;
	std::cout << "Nickname: " << this->book[index].getNick() << std::endl;
	std::cout << "Phone number: " << this->book[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << this->book[index].getSecret() << std::endl;
	std::cout << std::endl << "Press Enter to continue...";

	
	if (!std::getline(std::cin, ret) || std::cin.eof())
	{
		std::cout << std::endl << "Fast exit detected. Exiting..." << std::endl;
		exit(0);
	}
	system("clear");
}
