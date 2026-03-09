/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravazque <ravazque@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 04:00:00 by ravazque          #+#    #+#             */
/*   Updated: 2026/03/09 19:39:05 by ravazque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

int main(int argc, char *argv[])
{
	(void)argv;

	if (argc != 1)
	{
		std::cerr << "Please do not add arguments to the executable." << std::endl;
		return (1);
	}

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(0.0f, 10.0f);

	Point inside(2.0f, 2.0f);
	Point outside(10.0f, 10.0f);
	Point on_edge(5.0f, 0.0f);
	Point on_vertex(0.0f, 0.0f);
	Point on_hypotenuse(5.0f, 5.0f);
	Point barely_inside(1.0f, 1.0f);

	std::cout << "Triangle: A(0,0) B(10,0) C(0,10)" << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "Point (2,2) inside:       " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
	std::cout << "Point (10,10) outside:    " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
	std::cout << "Point (5,0) on edge:      " << (bsp(a, b, c, on_edge) ? "true" : "false") << std::endl;
	std::cout << "Point (0,0) on vertex:    " << (bsp(a, b, c, on_vertex) ? "true" : "false") << std::endl;
	std::cout << "Point (5,5) on hypot:     " << (bsp(a, b, c, on_hypotenuse) ? "true" : "false") << std::endl;
	std::cout << "Point (1,1) barely in:    " << (bsp(a, b, c, barely_inside) ? "true" : "false") << std::endl;

	return (0);
}
