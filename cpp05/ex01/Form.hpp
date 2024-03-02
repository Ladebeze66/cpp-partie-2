/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/26 15:57:56 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp" // Assurez-vous que cette classe est bien définie
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	//constructueur
	AForm(const::std::string& name);
	AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
	// Constructeur par copie
	AForm(const AForm& other);
	// Opérateur d'affectation
	AForm& operator=(const AForm& other);
	// Destructeur
	~AForm();


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
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
