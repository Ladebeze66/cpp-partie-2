/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 20:05:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/02 20:31:33 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // Pour size_t
#include <stdexcept> // Pour std::out_of_range
#include <iostream>

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

template<typename T>
class Array
{
private:
	T* elements;
	size_t n;

public:
	// Constructeur par défaut
	Array() : elements(new T[0]), n(0)
	{
		std::cout << GREEN << "Array default constructor called!" << RESET << std::endl;
	}

	// Constructeur avec taille
	Array(unsigned int n) : elements(new T[n]), n(n)
	{
		std::cout << GREEN << "Array with size constructor called!" << RESET << std::endl;
	}

	// Constructeur de copie
	Array(const Array& other) : elements(new T[other.n]), n(other.n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			elements[i] = other.elements[i];
		}
	}
	// Destructeur
	~Array()
	{
		delete[] elements;
		std::cout << RED << "Array " << static_cast<void*>(this->elements) << " is destroyed!" << RESET << std::endl;
	}
	// Opérateur d'assignation
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] elements;
			n = other.n;
			elements = new T[n];
			for (size_t i = 0; i < n; ++i)
			{
				elements[i] = other.elements[i];
			}
		}
		return (*this);
	}
	// Accès aux éléments
	T& operator[](size_t index)
	{
		if (index >= n) throw std::out_of_range("Index out of bounds");
		return (elements[index]);
	}
	// Taille du tableau
	size_t size() const
	{
		return (n);
	}
};

#endif
