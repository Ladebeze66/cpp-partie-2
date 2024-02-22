/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:31:13 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/22 15:42:00 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << GREEN << "PresidentialPardonForm constructed for target: " << target << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm copy constructed for target: " << target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
		std::cout << "PresidentialPardonForm assigned from another form for target: " << target << std::endl;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destroyed for target: " << target << RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
	{
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > getGradeRequiredToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (target);
}