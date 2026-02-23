/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/RPN.hpp"
# include <stdexcept>
# include <sstream>

RPN::RPN(void) {}

RPN::RPN(const RPN &src) : _stack(src._stack) {}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
		_stack = src._stack;
	return (*this);
}

RPN::~RPN(void) {}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperator(int a, int b, char op) const
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error");
		return (a / b);
	}
	throw std::runtime_error("Error");
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && isOperator(token[0]))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(applyOperator(a, b, token[0]));
		}
		else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		{
			_stack.push(token[0] - '0');
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	int result = _stack.top();
	_stack.pop();
	return (result);
}
