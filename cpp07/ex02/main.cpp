/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:15:43 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/02 20:34:26 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = static_cast<int>(i * 2);
		std::cout << BLUE << "intArray[" << i << "] = " << RESET << intArray[i] << std::endl;
	}

	// Test de copie
	Array<int> copiedArray = intArray;
	std::cout << GREEN << "copiedArray size: " << RESET << copiedArray.size() << std::endl;

	// Modifier l'original ne devrait pas affecter la copie
	intArray[0] = 100;
	std::cout << YELLOW << "\nAfter modification: " << RESET << std::endl;
	std::cout << "intArray[0] = " << intArray[0] << ", copiedArray[0] = " << copiedArray[0] << std::endl;

	// Test d'accès hors limites
	try
	{
		intArray[intArray.size()] = 10; // Devrait lancer une exception
	}
	catch (const std::out_of_range& e)
	{
		std::cout << RED << "\nException caught: " << RESET << e.what() << std::endl;
	}
	return (0);
}
