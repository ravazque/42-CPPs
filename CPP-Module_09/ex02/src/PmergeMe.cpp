/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/PmergeMe.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <algorithm>
# include <sstream>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

bool PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (arg.empty())
			return (false);
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (arg[j] < '0' || arg[j] > '9')
				return (false);
		}
		long num = std::atol(argv[i]);
		if (num < 0 || num > INT_MAX)
			return (false);
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
	return (!_vec.empty());
}

std::vector<int> PmergeMe::getJacobsthalSequence(int n) const
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		int next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return (jacob);
}

void PmergeMe::binaryInsertVec(std::vector<int> &sorted, int value)
{
	int low = 0;
	int high = static_cast<int>(sorted.size());
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (sorted[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	sorted.insert(sorted.begin() + low, value);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &sorted, int value)
{
	int low = 0;
	int high = static_cast<int>(sorted.size());
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (sorted[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	sorted.insert(sorted.begin() + low, value);
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = (vec.size() % 2 != 0);

	if (hasStraggler)
		straggler = vec.back();

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	std::vector<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);

	sortVector(winners);

	std::vector<int> pend;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == winners[i])
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	std::vector<int> sorted(winners);

	if (!pend.empty())
		sorted.insert(sorted.begin(), pend[0]);

	std::vector<int> jacob = getJacobsthalSequence(static_cast<int>(pend.size()));
	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty())
		inserted[0] = true;

	for (size_t k = 2; k < jacob.size(); k++)
	{
		int idx = jacob[k];
		if (idx > static_cast<int>(pend.size()))
			idx = static_cast<int>(pend.size());
		for (int i = idx - 1; i >= jacob[k - 1]; i--)
		{
			if (i >= 0 && i < static_cast<int>(pend.size()) && !inserted[i])
			{
				binaryInsertVec(sorted, pend[i]);
				inserted[i] = true;
			}
		}
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			binaryInsertVec(sorted, pend[i]);
	}

	if (hasStraggler)
		binaryInsertVec(sorted, straggler);

	vec = sorted;
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = (deq.size() % 2 != 0);

	if (hasStraggler)
		straggler = deq.back();

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	std::deque<int> winners;
	for (size_t i = 0; i < pairs.size(); i++)
		winners.push_back(pairs[i].first);

	sortDeque(winners);

	std::deque<int> pend;
	for (size_t i = 0; i < winners.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == winners[i])
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + static_cast<long>(j));
				break;
			}
		}
	}

	std::deque<int> sorted(winners.begin(), winners.end());

	if (!pend.empty())
		sorted.insert(sorted.begin(), pend[0]);

	std::vector<int> jacob = getJacobsthalSequence(static_cast<int>(pend.size()));
	std::vector<bool> inserted(pend.size(), false);
	if (!pend.empty())
		inserted[0] = true;

	for (size_t k = 2; k < jacob.size(); k++)
	{
		int idx = jacob[k];
		if (idx > static_cast<int>(pend.size()))
			idx = static_cast<int>(pend.size());
		for (int i = idx - 1; i >= jacob[k - 1]; i--)
		{
			if (i >= 0 && i < static_cast<int>(pend.size()) && !inserted[i])
			{
				binaryInsertDeq(sorted, pend[i]);
				inserted[i] = true;
			}
		}
	}

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			binaryInsertDeq(sorted, pend[i]);
	}

	if (hasStraggler)
		binaryInsertDeq(sorted, straggler);

	deq.assign(sorted.begin(), sorted.end());
}

void PmergeMe::display(const std::string &label) const
{
	std::cout << label;
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	display("Before:");

	clock_t startVec = clock();
	sortVector(_vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	sortDeque(_deq);
	clock_t endDeq = clock();

	display("After: ");

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
