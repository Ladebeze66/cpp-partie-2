/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:23:49 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 18:37:30 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Constructeur par défaut
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
	std::cout << "MutantStack constructor called!" << std::endl;
}
// Constructeur de copie
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{
	std::cout << "Copy constructor called for MutantStack." << std::endl;
}
// Destructeur
template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
	std::cout << "MutantStack is destroyed!" << std::endl;
}
// Opérateur d'assignation
template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	std::cout << "Copy assignment MutantStack operator called" << std::endl;
	if (this != &other)
	{
		std::stack<T, Container>::operator=(other);
	}
	return (*this);
}
// Début de l'itérateur
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}
// Fin de l'itérateur
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}
// Début de l'itérateur constant
template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}
// Fin de l'itérateur constant
template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return (this->c.end());
}
