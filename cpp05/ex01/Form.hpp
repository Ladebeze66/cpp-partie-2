/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/12 14:43:02 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" // Assurez-vous que cette classe est bien définie
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	const
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	//constructueur
	Form(const::std::string& name);
	Form(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
	// Constructeur par copie
    Form(const Form& other);
	// Opérateur d'affectation
    Form& operator=(const Form& other);
	// Destructeur
    ~Form();


	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const noexcept override
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const noexcept override
		{
			return ("Grade too low");
		}
	};
};

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
