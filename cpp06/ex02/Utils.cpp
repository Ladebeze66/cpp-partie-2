/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:33:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/27 15:07:41 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int choice = rand() % 3;
	switch (choice)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return (NULL); // Par défaut, retourne NULL si aucun cas n'est sélectionné.
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) std::cout << "A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "C\n";
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p); std::cout << "A\n"; return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p); std::cout << "B\n"; return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p); std::cout << "C\n"; return;
	} catch (...) {}
}
