/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:39:51 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/11 16:05:55 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string& name)
	: name(name), isSigned(false), gradeRequiredToSign(1), gradeRequiredToExecute(1)
{
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
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
}
Form& Form::operator=(const Form& other)
{
	(void)other;
	return (*this);
}

Form::~Form()
{
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

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form: " << form.getName()
	   << ", Status: " << (form.getIsSigned() ? "Signed" : "Not signed")
	   << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
	   << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
	return os;
}
