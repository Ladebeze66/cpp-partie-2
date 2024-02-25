/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:55:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 18:03:43 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>
#include <exception>

int main()
{
	std::cout << CYAN << "\n--- Creation ---\n\n" << RESET;
	// Création des bureaucrates
	Bureaucrat john("John", 2);
	Bureaucrat doe("Doe", 150);

	// Création d'un intern
	Intern someRandomIntern;

	// Utilisation de l'intern pour créer des formulaires
	AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "Home");
	AForm* robot = someRandomIntern.makeForm("robotomy request", "Robot");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Criminal");
	AForm* unknown = someRandomIntern.makeForm("unknown form", "Nowhere"); // Test d'un formulaire inconnu

	// Tentatives de signature et d'exécution des formulaires par John
	std::cout << CYAN << "\n--- John tries to sign and execute forms ---\n\n" << RESET;
	if (shrub)
	{
		john.signForm(*shrub);
		john.executeForm(*shrub);
	}
	if (robot)
	{
		john.signForm(*robot);
		john.executeForm(*robot);
	}
	if (pardon)
	{
		john.signForm(*pardon);
		john.executeForm(*pardon);
	}

	// Tentatives de signature et d'exécution des formulaires par Doe
	std::cout << CYAN << "\n--- Doe tries to sign and execute forms ---\n\n" << RESET;
	if (shrub)
	{
		doe.signForm(*shrub);
		doe.executeForm(*shrub);
	}
	if (robot)
	{
		doe.executeForm(*robot);
	}

	// Test avec un formulaire déjà signé
	std::cout << CYAN << "\n--- Testing with already signed form ---\n\n" << RESET;
	if (shrub)
	{
		john.signForm(*shrub); // shrub est déjà signé par John plus tôt
		john.executeForm(*shrub);
	}

	// Nettoyage des formulaires créés
	delete shrub;
	delete robot;
	delete pardon;
	delete unknown;

	return (0);
}
