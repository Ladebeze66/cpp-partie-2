/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:55:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/21 15:21:24 by fgras-ca         ###   ########.fr       */
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
	Bureaucrat john("John", 2);
	Bureaucrat doe("Doe", 150);

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Robot");
	PresidentialPardonForm pardon("Criminal");

	try {
		john.signForm(shrub);
		john.executeForm(shrub);

		john.signForm(robot);
		john.executeForm(robot);

		john.signForm(pardon);
		john.executeForm(pardon);

		// Tester avec un bureaucrate de grade insuffisant
		doe.signForm(shrub);
		doe.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
