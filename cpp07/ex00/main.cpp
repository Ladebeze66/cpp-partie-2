/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:06:16 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/13 10:51:58 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << RED << "a = " << RESET << a << RED << ", b = " << RESET << b << std::endl;
	std::cout << GREEN << "min( a, b ) = " << RESET << ::min(a, b) << std::endl;
	std::cout << YELLOW << "max( a, b ) = " << RESET << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << RED << "c = " << RESET << c << RED << ", d = " << RESET << d << std::endl;
	std::cout << GREEN << "min( c, d ) = " << RESET << ::min(c, d) << std::endl;
	std::cout << YELLOW << "max( c, d ) = " << RESET << ::max(c, d) << std::endl;

	return (0);
}