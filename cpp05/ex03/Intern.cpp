/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:27:11 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 18:05:57 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called!" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	*this = other;
	std::cout << CYAN << "Copy constructor called for Intern." << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED << "Intern is destroyed!" << RESET << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm* form = NULL;
	if (formName == "shrubbery creation")
	{
		form = new ShrubberyCreationForm(target);
		std::cout << BLUE << "Intern creates ShruberryCreationForm" << RESET << std::endl;
	}
	else if (formName == "robotomy request")
	{
		form = new RobotomyRequestForm(target);
		std::cout << BLUE << "Intern creates RobotomyRequestForm" << RESET << std::endl;
	}
	else if (formName == "presidential pardon")
	{
		form = new PresidentialPardonForm(target);
		std::cout << BLUE << "Intern creates PresidentialPardonForm" << RESET << std::endl;
	}
	else
	{
		std::cerr << RED << "Error: Request form " << formName << " is unknown: " << target << RESET << std::endl;
	}
	return (form);
}