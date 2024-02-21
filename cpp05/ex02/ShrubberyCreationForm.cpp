/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:52 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/21 15:39:36 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called for target: " << target << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{
	std::cout << CYAN << "Copy constructor called for ShrubberyCreationForm with target: " << target << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // Cette opération n'a pas d'effet réel si AForm n'implémente pas operator= pour les champs non statiques.
		target = other.target;
		std::cout << CYAN << "Assignment operator called for ShrubberyCreationForm with target: " << target << RESET << std::endl;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm for target: " << target << " is destroyed!" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// Vérification si le formulaire est signé et si le grade de l'exécuteur est suffisant
	if (!getIsSigned())
		throw NotSignedException(); // Assurez-vous que cette exception est correctement définie dans AForm
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw GradeTooLowException();

	std::ofstream ofs(target + "_shrubbery");
	if (!ofs)
	{
		std::cerr << "Failed to create file " << target << "_shrubbery" << std::endl;
		return ;
	}
	ofs << "ASCII trees" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (target);
}
