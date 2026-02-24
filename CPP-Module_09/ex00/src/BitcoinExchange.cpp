/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:15:37 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/20 09:44:12 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/BitcoinExchange.hpp"
# include <fstream>
# include <iostream>
# include <sstream>
# include <cstdlib>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _database(src._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		_database = src._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (leap ? 29 : 28))
			return (false);
	}
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string &value, float &result) const
{
	if (value.empty())
		return (false);

	char *end;
	result = std::strtof(value.c_str(), &end);
	if (*end != '\0')
		return (false);
	return (true);
}

float BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

	if (it != _database.end() && it->first == date)
		return (it->second);
	if (it == _database.begin())
		return (-1);
	--it;
	return (it->second);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);
		float rate = std::strtof(value.c_str(), NULL);
		_database[date] = rate;
	}
	file.close();
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);

		while (!date.empty() && date[date.length() - 1] == ' ')
			date.erase(date.length() - 1);
		while (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = getRate(date);
		if (rate < 0)
		{
			std::cerr << "Error: date too early." << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	file.close();
}
