/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:29:10 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/13 15:05:22 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>
#include <cstdlib>

int main()
{
	MutantStack<int> mstack;

	// Ajout d'éléments dans la MutantStack
	mstack.push(5);
	std::cout << GREEN << "Pushed: 5\n" << RESET;
	mstack.push(17);
	std::cout << GREEN << "Pushed: 17\n" << RESET;

	// Affichage du dernier élément ajouté (top de la pile)
	std::cout << YELLOW << "Current top: " << mstack.top() <<  RESET << std::endl; // Devrait afficher 17

	// Suppression du dernier élément
	mstack.pop();
	std::cout << RED << "Popped one element\n" << RESET;

	// Affichage de la taille actuelle de la pile
	std::cout << BLUE << "Size after pop: " << mstack.size() << RESET << std::endl; // Devrait afficher 1

	// Ajout de plusieurs éléments
	mstack.push(3); std::cout << GREEN << "Pushed: 3\n" << RESET;
	mstack.push(5); std::cout << GREEN << "Pushed: 5\n" << RESET;
	mstack.push(737); std::cout << GREEN << "Pushed: 737\n" << RESET;
	// [...]
	mstack.push(0); std::cout << GREEN << "Pushed: 0\n" << RESET;

	// Itération à travers la MutantStack pour afficher tous les éléments
	std::cout << ORANGE << "\nIterating through MutantStack:\n" << RESET;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for (; it != ite; ++it)
	{
		std::cout << *it << std::endl; // Affiche chaque élément
	}

	// Démonstration de la conversion d'une MutantStack en std::stack standard
	std::stack<int> s(mstack);
	std::cout << GREEN << "\nConverted to std::stack. Size: " << s.size() << RESET << std::endl;

	while (!mstack.empty())
	{
		mstack.pop();
	}

	std::cout << ORANGE << "Enter numbers to add to the stack (type 'done' to finish):" << RESET << std::endl;
	std::string input;
	while (std::cin >> input && input != "done")
	{
		mstack.push(std::atoi(input.c_str()));
	}

	std::cout << MAGENTA << "Stack now contains:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << "Popping the last element." << std::endl;
	if (!mstack.empty()) {
		mstack.pop();
	}

	std::cout << RED << "Stack after pop:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << RED << "Enter value to remove from stack:" << RESET << std::endl;
	int valueToRemove;
	std::cin >> valueToRemove;

	std::vector<int> tempContainer;
	while (!mstack.empty())
	{
		if (mstack.top() == valueToRemove)
		{
			break; // Found the value to remove
		}
		tempContainer.push_back(mstack.top());
		mstack.pop();
	}

	// Pop the target value if it was found
	if (!mstack.empty())
	{
		mstack.pop();
	}

	// Push back the remaining elements
	for (std::vector<int>::reverse_iterator it = tempContainer.rbegin(); it != tempContainer.rend(); ++it)
	{
		mstack.push(*it);
	}

	std::cout << GREEN << "Stack after removing the target value:" << RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";

	return (0);
}
