/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:12:20 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/08 14:08:06 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructeur par défaut
PmergeMe::PmergeMe()
{
	std::cout << GREEN << "PmergeMe default constructor called!" << RESET << std::endl;
}
// Destructeur
PmergeMe::~PmergeMe()
{
	std::cout << RED << "PmergeMe is destroyed!" << RESET << std::endl;
}
// Constructeur de copie
PmergeMe::PmergeMe(const PmergeMe& other)
{
	std::cout << CYAN << "Copy constructor called for PmergeMe." << RESET << std::endl;
	 (void)other;// La copie des membres pourrait être ajoutée ici si nécessaire
}
// Opérateur d'affectation
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	std::cout << YELLOW << "Copy assignment PmergeMe operator called." << RESET << std::endl;
	if (this != &other)
	{
		// Copie des membres pourrait être ajoutée ici si nécessaire
	}
	return (*this);
}

void PmergeMe::sortAndDisplay(const std::vector<int>& input)
{
	std::vector<int> data = input; // Copie pour permettre le tri
	measureAndSort(data, "std::vector<int>");
}

void PmergeMe::sortAndDisplay(const std::list<int>& input)
{
	std::list<int> data = input; // Copie pour permettre le tri
	measureAndSort(data, "std::list<int>");
}
// Fonction template pour appliquer un algorithme de tri similaire à Ford-Johnson sur un conteneur générique
// Elle divise récursivement le conteneur et le fusionne en utilisant des stratégies d'insertion.
template<typename Container>
void PmergeMe::fordJohnsonLikeSort(Container& container, typename Container::iterator begin, typename Container::iterator end)
{
	if (std::distance(begin, end) <= 1)
		return; // Condition de base pour arrêter la récursivité

	typename Container::iterator median = begin;
	std::advance(median, std::distance(begin, end) / 2); // Calcul de la position médiane
	// Tri récursif des moitiés
	fordJohnsonLikeSort(container, begin, median);
	fordJohnsonLikeSort(container, median, end);
	// La fusion ou l'insertion pourrait être effectuée ici
	// Exemple simplifié utilisant std::inplace_merge pour des conteneurs supportant les itérateurs aléatoires
	std::inplace_merge(begin, median, end);
}
// Affichage de la séquence
template<typename Container>
void PmergeMe::displaySequence(const Container& sequence, const std::string& prefix)
{
	std::cout << RED << prefix << ": " << RESET;
	for (typename Container::const_iterator it = sequence.begin(); it != sequence.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
// Mesure du temps de tri et affichage
template<typename Container>
void PmergeMe::measureAndSort(Container& container, const std::string& containerName)
{
	displaySequence(container, "Before");

	std::clock_t start = std::clock();
	fordJohnsonLikeSort(container, container.begin(), container.end());
	std::clock_t end = std::clock();

	displaySequence(container, "After");

	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000; // Convertir en microsecondes
	std::cout << CYAN << "Time to process a range of " << container.size()
			  << " elements with " << containerName << " : " << duration << " us\n" << RESET;
}
// Spécialisations explicites pour std::vector<int> et std::list<int>
template void PmergeMe::fordJohnsonLikeSort<std::vector<int> >(std::vector<int>&, std::vector<int>::iterator, std::vector<int>::iterator);
template void PmergeMe::fordJohnsonLikeSort<std::list<int> >(std::list<int>&, std::list<int>::iterator, std::list<int>::iterator);

template void PmergeMe::displaySequence<std::vector<int> >(const std::vector<int>&, const std::string&);
template void PmergeMe::displaySequence<std::list<int> >(const std::list<int>&, const std::string&);

template void PmergeMe::measureAndSort<std::vector<int> >(std::vector<int>&, const std::string&);

// Spécialisation explicite pour std::list<int>
template void PmergeMe::measureAndSort<std::list<int> >(std::list<int>&, const std::string&);
