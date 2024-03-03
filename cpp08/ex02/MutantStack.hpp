/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:22:10 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 18:35:45 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(); // Constructeur par défaut
	MutantStack(const MutantStack& other); // Constructeur de copie
	~MutantStack(); // Destructeur
	MutantStack& operator=(const MutantStack& other); // Opérateur d'assignation

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

private:
	using std::stack<T, Container>::c; // Utilisez 'c' pour accéder au conteneur sous-jacent
};

#include "MutantStack.tpp"
#endif
