/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:37:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/16 18:50:37 by fgras-ca         ###   ########.fr       */
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

public:
	//constructueur
	AForm();
	AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);
	// Constructeur par copie
    AForm(const AForm& other);
	// Opérateur d'affectation
    virtual AForm& operator=(const AForm& other);
	// Destructeur
    virtual ~AForm();


	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	virtual void beSigned(const Bureaucrat& bureaucrat);

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
std::ostream& operator<<(std::ostream& os, const AForm& aform);

#endif
