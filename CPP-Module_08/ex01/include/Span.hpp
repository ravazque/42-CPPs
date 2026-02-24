/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:09:53 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/17 15:41:08 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		~Span(void);

		Span	&operator=(const Span &src);

		void	addNumber(int number);

		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end)
		{
			unsigned int dist = 0;
			for (Iterator tmp = begin; tmp != end; ++tmp)
				dist++;
			if (_numbers.size() + dist > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class SpanFullException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

#endif
