/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:06:41 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/27 13:46:46 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <string>

int main()
{
	std::cout << YELLOW << "Enter a string to be stored in Data: " << RESET;
	std::string input;
	std::getline(std::cin, input); // Capture l'entrée utilisateur, incluant les espaces.

	Data data; // Création d'une instance de Data.
	data.dummy_str = input; // Stocke la chaîne saisie dans l'instance de Data.
	std::cout << CYAN << "Original data content: " << RESET << data.dummy_str << std::endl;

	// Sérialisation de l'adresse de l'instance de Data.
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << CYAN << "Serialized value (address as integer): " << RESET << serialized << std::endl;

	// Désérialisation de la valeur sérialisée pour obtenir le pointeur vers l'instance de Data.
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << CYAN << "Deserialized data content: "  << RESET << deserialized->dummy_str << std::endl;

	// Vérification de la cohérence entre l'instance originale et l'instance désérialisée.
	if (&data == deserialized)
	{
		std::cout << YELLOW << "Verification: Original and deserialized data point to the same instance." << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "Error: Original and deserialized data do not point to the same instance." << RESET << std::endl;
	}

	// Logs de l'entrée standard à la fin du programme
	std::cout << MAGENTA << "Final Log:" << RESET << std::endl;
	std::cout << CYAN << "- Original input: " << RESET << input << std::endl;
	std::cout << CYAN << "- Serialized value: " << RESET << serialized << std::endl;
	std::cout << CYAN << "- Deserialized content: " << RESET << deserialized->dummy_str << std::endl;
	std::cout << CYAN << "- Original and deserialized comparison: " << RESET << (&data == deserialized ? "Identical" : "Different") << std::endl;

	return (0);
}

