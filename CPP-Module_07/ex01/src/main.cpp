/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:25:41 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/15 17:31:09 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

void increment(int &x)
{
	x++;
}

int main(void)
{
	std::cout << "=== Int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	iter(intArr, 5, print<int>);

	std::cout << "\n=== After increment ===" << std::endl;
	iter(intArr, 5, increment);
	iter(intArr, 5, print<int>);

	std::cout << "\n=== String array ===" << std::endl;
	std::string strArr[] = {"Hello", "World", "42", "Madrid"};
	iter(strArr, 4, print<std::string>);

	std::cout << "\n=== Double array ===" << std::endl;
	double dblArr[] = {1.1, 2.2, 3.3};
	iter(dblArr, 3, print<double>);

	return (0);
}
