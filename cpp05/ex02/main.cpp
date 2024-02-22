/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:55:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/22 15:54:24 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main()
{
	// Création des bureaucrates
	Bureaucrat john("John", 2);
	Bureaucrat doe("Doe", 150);

	// Création des formulaires
	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Robot");
	PresidentialPardonForm pardon("Criminal");

	// Tentatives de signature et d'exécution des formulaires par John
	std::cout << "\n--- John tries to sign and execute forms ---\n";
	john.signForm(shrub);
	john.executeForm(shrub);

	john.signForm(robot);
	john.executeForm(robot);

	john.signForm(pardon);
	john.executeForm(pardon);

	// Tentatives de signature et d'exécution des formulaires par Doe
	std::cout << "\n--- Doe tries to sign and execute forms ---\n";
	try
	{
		doe.signForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		doe.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		doe.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Tentatives de signature et d'exécution des formulaires avec gestion des exceptions
	std::cout << "\n--- Additional tests with exception handling ---\n";
	try
	{
		doe.signForm(robot);
		doe.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		doe.signForm(pardon);
		doe.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test avec un formulaire déjà signé
	std::cout << "\n--- Testing with already signed form ---\n";
	try
	{
		john.signForm(shrub); // shrub est déjà signé par John plus tôt
		john.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}

