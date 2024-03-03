/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:00:49 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 17:59:58 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> // Pour std::rand et std::srand
#include <ctime>   // Pour std::time
#include <set>

int main()
{
	// Test initial
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Ajout de tests pour les exceptions
	try
	{
		Span emptySpan(10);
		emptySpan.shortestSpan();
	}
	catch (std::exception& e)
	{
		std::cout << RED << "\nException caught for shortestSpan with less than 2 elements: " << RESET << e.what() << std::endl;
	}

	try
	{
		Span singleElementSpan(10);
		singleElementSpan.addNumber(1);
		singleElementSpan.longestSpan();
	}
	catch (std::exception& e)
	{
	std::cout << RED << "Exception caught for longestSpan with less than 2 elements: " << RESET << e.what() << std::endl;
	}

	try
	{
		Span fullSpan(1);
		fullSpan.addNumber(1);
		fullSpan.addNumber(2); // Devrait lancer une exception
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught for adding to a full Span: " << RESET << e.what() << std::endl;
	}

	// Interaction en ligne de commande
	unsigned int N;
	std::cout << YELLOW << "\nEnter the number of elements to generate: " << RESET;
	std::cin >> N;

	Span userSpan(N);
	std::set<int> uniqueNumbers;
	while(uniqueNumbers.size() < N)
	{
		int number = std::rand() % 100000; // Générer un nombre aléatoire entre 0 et 999
		if(uniqueNumbers.insert(number).second)
		{ // Vérifie si l'insertion est réussie (élément n'était pas déjà présent)
			userSpan.addNumber(number);
			std::cout << BLUE << "Generated number: " << RESET << number << std::endl;
		}
	}

	if (N > 1)
	{
		std::cout << CYAN << "Shortest span (userSpan): " << RESET << userSpan.shortestSpan() << std::endl;
		std::cout << CYAN << "Longest span (userSpan): " << RESET << userSpan.longestSpan() << std::endl;
	}
	else
	{
		std::cout << RED << "Not enough elements to calculate spans." << RESET << std::endl;
	}

	return (0);
}
