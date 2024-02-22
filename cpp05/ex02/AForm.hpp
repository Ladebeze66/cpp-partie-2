/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/22 13:49:48 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp" // Assurez-vous que cette classe est bien définie
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

protected:
	std::string target;

public:
	//constructueur
	AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
	// Constructeur par copie
	AForm(const AForm& other);
	// Opérateur d'affectation
	AForm& operator=(const AForm& other);
	// Destructeur
	virtual ~AForm();


	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	virtual std::string getTarget() const {return target;}

	virtual void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
