/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:26:15 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/02 20:03:13 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cctype> // Pour std::toupper
#include <cstring> // Pour la fonction std::strlen et std::strcpy

// Fonction pour doubler les valeurs
void doubleValue(int& value)
{
	value *= 2;
}

// Fonction pour convertir une chaîne en majuscules
void toUpperCase(std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper(str[i]);
	}
}

// Un objet personnalisé pour démontrer l'utilisation avec iter
class Person
{
public:
	std::string name;
	int age;

	// Constructeur par défaut
	Person() : name(""), age(0) {}

	// Constructeur paramétrique
	Person(std::string n, int a) : name(n), age(a) {}

	// Destructeur
	~Person() {}

	// Constructeur de copie
	Person(const Person& other) : name(other.name), age(other.age) {}

	// Opérateur d'affectation
	Person& operator=(const Person& other)
	{
		if (this != &other) // Protection contre l'auto-affectation
		{
			name = other.name;
			age = other.age;
		}
		return (*this);
	}
};

// Fonction pour afficher les attributs d'un objet Person
void displayPerson(Person& person)
{
	std::cout << person.name << ", " << person.age << " years old" << std::endl;
}

int main()
{
	int nums[] = {1, 2, 3, 4, 5};
	std::string strings[] = {"hello", "world", "iter", "function", "test"};
	Person people[3] =
	{
		Person("Alice", 30),
		Person("Bob", 25),
		Person("Charlie", 35)
	};

	std::cout << YELLOW << "Original nums: " << RESET;
	for (int i = 0; i < 5; ++i) std::cout << nums[i] << " ";
	std::cout << std::endl;

	iter(nums, 5, doubleValue);

	std::cout << YELLOW << "\nDoubled nums: " << RESET;
	for (int i = 0; i < 5; ++i) std::cout << nums[i] << " ";
	std::cout << std::endl;

	iter(strings, 5, toUpperCase);

	std::cout << MAGENTA << "\nStrings to upper case:" << RESET << std::endl;
	for (int i = 0; i < 5; ++i) std::cout << strings[i] << std::endl;

	std::cout << RED << "\nDisplay people:" << RESET << std::endl;
	iter(people, 3, displayPerson);

	return (0);
}
