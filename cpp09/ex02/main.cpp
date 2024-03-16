/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:25:02 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/16 17:10:14 by fgras-ca         ###   ########.fr       */
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

	for(int i = 1; i < argc; ++i)
	{
		errno = 0; // Réinitialiser errno avant la conversion
		char* endPtr;
		long value = std::strtol(argv[i], &endPtr, 10);
		// Vérifier si la conversion a réussi et que toute la chaîne a été consommée
		if (*endPtr != '\0' || errno == ERANGE || value < 0 || value > INT_MAX)
		{
			std::cerr << RED << "Error: Argument \"" << argv[i] << "\" is not a valid positive integer or it is out of the int range." << RESET << std::endl;
			return (1);
		}
		vectorInput.push_back(static_cast<int>(value));
		listInput.push_back(static_cast<int>(value));
	}

	std::cout << ORANGE << "Processing with std::vector<int>..." << RESET << std::endl;
	pmerge.sortAndDisplay(vectorInput);

	std::cout << ORANGE << "\nProcessing with std::list<int>..." << RESET << std::endl;
	pmerge.sortAndDisplay(listInput);

	return (0);
}
