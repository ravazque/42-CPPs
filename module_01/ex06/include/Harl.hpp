/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:45:58 by ravazque          #+#    #+#             */
/*   Updated: 2025/11/19 13:07:01 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL__
# define __HARL__

# include <string>
# include <iostream>

typedef std::string string;

class Harl
{
	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:

		void complain( string level );
	
};

#endif
