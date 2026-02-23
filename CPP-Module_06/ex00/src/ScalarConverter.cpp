/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:40:06 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 23:00:14 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

static bool isChar(const std::string &literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool isSpecial(const std::string &literal)
{
	return (literal == "nan" || literal == "nanf" ||
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff" ||
			literal == "inf" || literal == "inff");
}

static bool isInt(const std::string &literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i >= literal.length())
		return false;

	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

static bool isFloat(const std::string &literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;

	std::string withoutF = literal.substr(0, literal.length() - 1);
	if (withoutF.empty())
		return false;

	size_t i = 0;
	if (withoutF[i] == '+' || withoutF[i] == '-')
		i++;

	bool hasDot = false;
	bool hasDigit = false;

	while (i < withoutF.length())
	{
		if (withoutF[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(withoutF[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	return hasDigit && hasDot;
}

static bool isDouble(const std::string &literal)
{
	if (literal.empty())
		return false;

	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;

	bool hasDot = false;
	bool hasDigit = false;

	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(literal[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	return hasDigit && hasDot;
}

static void convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

static void convertFromInt(int n)
{
	// char
	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;

	// int
	std::cout << "int: " << n << std::endl;

	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;

	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void convertFromFloat(float f)
{
	// char
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "char: impossible" << std::endl;
	else if (f < 32 || f >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	// int
	if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
}

static void convertFromDouble(double d)
{
	// char
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (d < 32 || d >= 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	// int
	if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;

	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isChar(literal))
	{
		convertFromChar(literal[1]);
	}
	else if (isSpecial(literal))
	{
		double d;
		if (literal == "nan" || literal == "nanf")
			d = std::numeric_limits<double>::quiet_NaN();
		else if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
			d = std::numeric_limits<double>::infinity();
		else
			d = -std::numeric_limits<double>::infinity();
		convertFromDouble(d);
	}
	else if (isInt(literal))
	{
		errno = 0;
		char *end;
		long num = std::strtol(literal.c_str(), &end, 10);

		if (errno == ERANGE || num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		else
			convertFromInt(static_cast<int>(num));
	}
	else if (isFloat(literal))
	{
		errno = 0;
		char *end;
		float f = std::strtof(literal.c_str(), &end);

		if (errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		else
			convertFromFloat(f);
	}
	else if (isDouble(literal))
	{
		errno = 0;
		char *end;
		double d = std::strtod(literal.c_str(), &end);

		if (errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		else
			convertFromDouble(d);
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

