/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/23 12:00:00 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);

		std::vector<int>	getJacobsthalSequence(int n) const;

		void	sortVector(std::vector<int> &vec);
		void	sortDeque(std::deque<int> &deq);

		void	binaryInsertVec(std::vector<int> &sorted, int value);
		void	binaryInsertDeq(std::deque<int> &sorted, int value);

	public:
		PmergeMe(void);
		~PmergeMe(void);

		bool	parseArgs(int argc, char **argv);
		void	sort(void);
		void	display(const std::string &label) const;
};

#endif
