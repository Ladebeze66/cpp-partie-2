/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:25:02 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/08 13:50:25 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << RED << "Usage: " << argv[0] << " <sequence of integers>" << RESET << std::endl;
		return (1);
	}

	PmergeMe pmerge;
	std::vector<int> vectorInput;
	std::list<int> listInput;

	// Remplir les conteneurs avec les entiers fournis en arguments
	for(int i = 1; i < argc; ++i)
	{
		int value = std::atoi(argv[i]);
		if(value < 0)
		{
			std::cerr << RED << "Error: Only positive integers are allowed." << RESET << std::endl;
			return (1);
		}
		vectorInput.push_back(value);
		listInput.push_back(value);
	}

	// Traitement et affichage pour std::vector
	std::cout << ORANGE << "Processing with std::vector<int>..." << RESET << std::endl;
	pmerge.sortAndDisplay(vectorInput);

	// Traitement et affichage pour std::list
	std::cout << ORANGE << "\nProcessing with std::list<int>..." << RESET << std::endl;
	pmerge.sortAndDisplay(listInput);

	return (0);
}
