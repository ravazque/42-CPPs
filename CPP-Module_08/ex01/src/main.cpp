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

#include "../include/Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(void)
{
	std::cout << "=== Subject test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n=== Full exception ===" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Not enough elements ===" << std::endl;
	try
	{
		Span small(1);
		small.addNumber(1);
		small.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== Range of iterators (10000 elements) ===" << std::endl;
	Span big(10000);
	std::vector<int> range;
	for (int i = 0; i < 10000; i++)
		range.push_back(i);
	big.addRange(range.begin(), range.end());
	std::cout << "Shortest: " << big.shortestSpan() << std::endl;
	std::cout << "Longest: " << big.longestSpan() << std::endl;

	return (0);
}
