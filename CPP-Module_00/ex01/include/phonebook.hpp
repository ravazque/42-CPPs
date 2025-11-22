/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:14:44 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 20:25:27 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK__HPP__
# define __PHONEBOOK__HPP__

# include <iostream>
# include <cctype>
# include <string>
# include <unistd.h>
# include <cstdlib>
# include <iomanip>
# include <cstdio>

typedef std::string string;

class	contact
{
	public:
		contact();
		~contact();

		void	setName(string name);
		void	setLast(string last);
		void	setNick(string nick);
		void	setPhone(string phone);
		void	setSecret(string secret);

		string		getName() const;
		string		getLast() const;
		string		getNick() const;
		string		getPhone() const;
		string		getSecret() const;

	private:
		string	name;
		string	last;
		string	nick;
		string	phone;
		string	secret;
};

class	phoneBook
{
	public:
		phoneBook();
		~phoneBook();

		void	add_contact();
		void	search_contact();

	private:
		const	int	max_contacts;
		int			number;
		int			contacts;
		contact		book[8];

		bool	get_input(string &input, const string &prompt);
};

#endif
