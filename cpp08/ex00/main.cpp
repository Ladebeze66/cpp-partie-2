/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:26:05 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 15:08:46 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	// Exemple avec std::vector<int>
	std::vector<int> vecInt;
	vecInt.push_back(1);
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(4);
	vecInt.push_back(5);
	std::cout << MAGENTA << "Testing with std::vector<int>: (1, 2, 3, 4, 5) find 3 and 6" << RESET << std::endl;
	easyfind(vecInt, 3);
	easyfind(vecInt, 6);

	// Exemple avec std::list<int>
	std::list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);
	listInt.push_back(30);
	listInt.push_back(40);
	listInt.push_back(50);
	std::cout << MAGENTA << "\nTesting with std::list<int>: (10, 20, 30, 40, 50) find 30 and 60" << RESET << std::endl;
	easyfind(listInt, 30);
	easyfind(listInt, 60);

	// Exemple avec std::vector<char>
	std::vector<char> vecChar;
	vecChar.push_back('a');
	vecChar.push_back('b');
	vecChar.push_back('c');
	vecChar.push_back('d');
	vecChar.push_back('e');
	std::cout << MAGENTA << "\nTesting with std::vector<char>: (a, b, c, d, e) find c and f" << RESET << std::endl;
	easyfind(vecChar, 'c'); // Note: 'c' est promu en int pour la comparaison
	easyfind(vecChar, 'f'); // Note: 'f' est promu en int pour la comparaison

	// Partie dynamique avec entrée utilisateur
	std::vector<int> vecUserInput;
	std::string line;

	std::cout << MAGENTA << "\nDynamic testing - Enter numbers (type 'end' to finish):" << RESET << std::endl;
	while (std::getline(std::cin, line) && line != "end")
	{
		vecUserInput.push_back(std::atoi(line.c_str()));
	}

	std::cout << CYAN << "Enter value to find:" << RESET << std::endl;
	int toFind;
	std::cin >> toFind;

	// Utilisation de easyfind avec le vecteur rempli dynamiquement
	easyfind(vecUserInput, toFind);

	return (0);
}
