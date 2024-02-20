/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:16:26 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/16 17:30:32 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructeur par défaut
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called!" << RESET << std::endl;
}
// Constructeur avec paramètres
Bureaucrat::Bureaucrat(const std::string& name, int grade) :name(name), grade(grade)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	this->grade = grade;
	std::cout << GREEN << "Bureaucrat " << this->name << " constructor called with grade " << this->grade << RESET << std::endl;
}
// Constructeur de copie
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << CYAN << "Copy constructor called for Bureaucrat " << this->name << RESET << std::endl;
}
// Opérateur d'affectation
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// L'attribut name étant const, nous ne pouvons pas le modifier. Seul grade est copié.
		this->grade = other.grade;
	}
	return (*this);
}
// Destructeur
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << this->name << " is destroyed!" << RESET << std::endl;
}
// Getter pour le nom
std::string Bureaucrat::getName() const
{
	return (this->name);
}
// Getter pour le grade
int Bureaucrat::getGrade() const
{
	return (this->grade);
}
// Incrémente le grade
void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	--grade;
}
// Décrémente le grade
void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
	++grade;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
// Méthodes pour les exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too hight\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}
// Surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
