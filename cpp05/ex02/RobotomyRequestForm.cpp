/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:25:21 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/11 15:08:54 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::initializeRandomSeed()
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL))); // Utilisez NULL au lieu de nullptr
		seeded = true;
	}
}

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called!" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	initializeRandomSeed();
	std::cout << GREEN << "RobotomyRequestForm constructor called for target: " << target << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
{
	std::cout << CYAN << "Copy constructor called for RobotomyRequestForm with target: " << target << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Note: Ceci n'aura aucun effet car AForm::operator= est supprimé ou non implémenté.
		target = other.target;
		// Log pour l'opération d'affectation
		std::cout << CYAN << "Assignment operator called for RobotomyRequestForm with target: " << target << RESET << std::endl;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm for target: " << target << " is destroyed!" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		throw NotSignedException();
	}
	if (executor.getGrade() > getGradeRequiredToExecute())
	{
		throw GradeTooLowException();
	}

	std::cout << "\nDrilling noises... Zzzzzz..." << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << GREEN << target << " has been robotomized successfully.\n" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "The robotomy on " << target << " failed.\n" << RESET << std::endl;
	}
}

std::string RobotomyRequestForm::getTarget() const
{
	return (target); // Assurez-vous que 'target' est bien défini et accessible
}
