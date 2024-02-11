/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:57:28 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/11 14:59:51 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <string>
#include <exception>
#include <iostream>

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw() override
		{
			return ("Grade trop élevé");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw() override
		{
			return ("Grade trop bas");
		}
	};

private:
	const std::string name;
	int grade;

public:
	Bureaucrat(const std::string &nom, int grade); // Constructeur
	Bureaucrat(const Bureaucrat& other) = default; // Constructeur par copie
	Bureaucrat& operator=(const Bureaucrat& other) = default; // Opérateur d'affectation
	~Bureaucrat() = default; // Destructeur

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
