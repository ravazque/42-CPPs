/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:57:43 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/06 12:59:08 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		for(int i = 1; argv[i]; i++)
		{
			for(int j = 0; argv[i][j]; j++)
			{
				if (strncmp(&argv[i][j], "ñ", 2) == 0)
				{
					std::cout << "Ñ";
					j++;
				}
				else
					std::cout << (char)toupper(argv[i][j]);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "Por favor introduce un argumento válido\n";
	return 0;
}
