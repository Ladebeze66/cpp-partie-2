/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:17:28 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/07 14:00:07 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <ctime>
#include <algorithm> // Pour les conteneurs supportant le tri direct
#include <iterator>  // Pour std::distance et std::advance
#include <cstdlib> // Pour std::atoi

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define ORANGE	"\033[38;5;214m"

// Définition de la classe PmergeMe pour implémenter un algorithme de tri inspiré du Ford-Johnson
class PmergeMe
{
public:
	// Constructeur par défaut
	PmergeMe();
	// Destructeur
	~PmergeMe();
	// Constructeur de copie
	PmergeMe(const PmergeMe& other);
	// Opérateur d'affectation
	PmergeMe& operator=(const PmergeMe& other);
	// Méthodes publiques pour trier et afficher des séquences d'entiers
	// Ces méthodes acceptent un std::vector<int> ou un std::list<int> comme conteneur d'entrée
	void sortAndDisplay(const std::vector<int>& input);
	void sortAndDisplay(const std::list<int>& input);

private:
	// Fonction template pour le tri récursif inspiré de Ford-Johnson
	// C'est une version simplifiée destinée à montrer la structure générale et à être adaptée
	template<typename Container>
	void fordJohnsonLikeSort(Container& container, typename Container::iterator begin, typename Container::iterator end);
	// Fonction template pour fusionner deux sous-séquences triées
	// Utilise std::inplace_merge pour les conteneurs supportant les itérateurs aléatoires
	template<typename Container>
	void merge(Container& container, typename Container::iterator begin, typename Container::iterator median, typename Container::iterator end);
	// Fonction template pour afficher les éléments d'une séquence, précédés d'un préfixe
	template<typename Container>
	void displaySequence(const Container& sequence, const std::string& prefix);
	// Fonction template pour mesurer et afficher le temps de tri d'une séquence
	template<typename Container>
	void measureAndSort(Container& container, const std::string& containerName);
};

#endif
