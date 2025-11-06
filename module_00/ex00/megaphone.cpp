/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:30:41 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 13:31:04 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{
	int	i = 1;
	int	j;
	
	if (argc == 1)
	{
		std::cout << "Please enter arguments for the program to work!";
		std::cout << std::endl;
		return (1);
	}
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (strncmp(&argv[i][j], "ñ", 2) == 0)
			{
				std::cout << "Ñ";
				j++;
			}
			else
				std::cout << (char)toupper(argv[i][j]);
			j++;
		}
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
