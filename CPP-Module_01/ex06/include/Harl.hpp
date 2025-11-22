/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:45:58 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 20:25:05 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
# define __HARL_HPP__

# include <string>
# include <iostream>

typedef std::string string;

class Harl
{
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:

		void	complain( string level );
	
};

#endif
