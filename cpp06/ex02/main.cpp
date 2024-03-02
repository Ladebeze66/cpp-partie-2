/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:44:31 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/27 15:14:37 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <iostream>

int main()
{
	Base* base = generate();

	std::cout << RED << "Identify by pointer: " << RESET;
	identify(base); // Identifier par pointeur

	std::cout << RED << "Identify by reference: " << RESET;
	identify(*base); // Identifier par référence

	delete base; // Nettoyer la mémoire

	A a;
	B b;
	C c;

	std::cout << YELLOW << "\nDirect identification:" << RESET << std::endl;

	std::cout << MAGENTA << "Identify A by reference: " << RESET;
	identify(a);

	std::cout << MAGENTA << "Identify B by reference: " << RESET;
	identify(b);

	std::cout << MAGENTA << "Identify C by reference: " << RESET;
	identify(c);
	return (0);
}
