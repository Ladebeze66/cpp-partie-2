/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/16 18:26:09 by fgras-ca         ###   ########.fr       */
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
	bool isSigned;
	const int gradeRequiredToSign;
	const int gradeRequiredToExecute;

public:
	//constructueur
	Form();
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
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const noexcept override;
	};
};

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
