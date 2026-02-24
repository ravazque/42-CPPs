/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:09:53 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/18 09:27:35 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Span.hpp"
# include <climits>

Span::Span(void) : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers) {}

Span::~Span(void) {}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<unsigned int>(max - min));
}

const char *Span::SpanFullException::what(void) const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what(void) const throw()
{
	return ("Not enough elements to find a span");
}
