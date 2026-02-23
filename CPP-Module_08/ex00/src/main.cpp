/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void)
{
	std::cout << "=== Vector test ===" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 3);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 9);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(vec, 42);
	}
	catch (std::exception &e)
	{
		std::cout << "42: " << e.what() << std::endl;
	}

	std::cout << "\n=== List test ===" << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		easyfind(lst, 99);
	}
	catch (std::exception &e)
	{
		std::cout << "99: " << e.what() << std::endl;
	}

	std::cout << "\n=== Deque test ===" << std::endl;
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
