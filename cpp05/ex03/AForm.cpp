/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:39:51 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/11 15:11:19 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
	std::cout << GREEN << "AForm default constructor called!" << RESET << std::endl; 
}

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
	: name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
	{
		throw GradeTooHighException();
	}
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
	{
		throw GradeTooLowException();
	}
	std::cout << GREEN << "AForm" << this->name << "constructor called with grade to sign: " << this->gradeRequiredToSign << " and grade to execute: " << this->gradeRequiredToExecute << RESET << std::endl;
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
	std::cout << CYAN << "Copy constructor called for AForm " << this->name << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "AForm " << this->name << " is destroyed!" << RESET << std::endl;
}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getGradeRequiredToSign() const
{
	return (gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeRequiredToSign)
	{
		isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed.\n");
}

std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
	os << "AForm: " << aform.getName()
	   << ", Status: " << (aform.getIsSigned() ? "Signed" : "Not signed")
	   << ", Grade Required to Sign: " << aform.getGradeRequiredToSign()
	   << ", Grade Required to Execute: " << aform.getGradeRequiredToExecute();
	return (os);
}
