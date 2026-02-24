/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:52:43 by ravazque          #+#    #+#             */
/*   Updated: 2026/02/20 13:17:29 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<int>	_stack;

		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);

		bool	isOperator(char c) const;
		int		applyOperator(int a, int b, char op) const;

	public:
		RPN(void);
		~RPN(void);

		int		evaluate(const std::string &expression);
};

#endif
