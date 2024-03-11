/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:39:51 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/11 14:47:49 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
	std::cout << GREEN << "Form default constructor called!" << RESET << std::endl; 
}

Form::Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
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
	std::cout << GREEN << "Form" << this->name << "constructor called with grade to sign: " << this->gradeRequiredToSign << " and grade to execute: " << this->gradeRequiredToExecute << RESET << std::endl; 
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
	std::cout << CYAN << "Copy constructor called for Form " << this->name << RESET << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form " << this->name << " is destroyed!" << RESET << std::endl;
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
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

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too hight\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName()
	   << ", Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
	   << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
	   << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
	return (os);
}
