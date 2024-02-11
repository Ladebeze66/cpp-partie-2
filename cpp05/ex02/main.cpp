/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:55:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/11 15:38:42 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		// Création d'un bureaucrate avec un grade élevé
		Bureaucrat highRankBureaucrat("HighRank", 2);
		// Création d'un bureaucrate avec un grade bas
		Bureaucrat lowRankBureaucrat("LowRank", 149);
		Bureaucrat chief("Chief", 1);
		Bureaucrat intern("Intern", 150);

		// Création de formulaires
		Form highRequirementForm("HighRequirement", 1, 1); // Exige un grade très élevé pour signer
		Form lowRequirementForm("LowRequirement", 150, 150); // Peut être signé par n'importe quel bureaucrate
		Form formHigh("HighForm", 2, 5);

		// Tentative de signature des formulaires
		std::cout << CYAN << "Tentative de signature par HighRank:" << RESET << std::endl;
		highRankBureaucrat.signForm(highRequirementForm);
		highRankBureaucrat.signForm(lowRequirementForm);

		std::cout << CYAN << "\nTentative de signature par LowRank:" << RESET << std::endl;
		lowRankBureaucrat.signForm(highRequirementForm);
		lowRankBureaucrat.signForm(lowRequirementForm);

		std::cout << GREEN << "\nTenative de signature formHight par chief: " << RESET << std::endl;
		chief.signForm(formHigh);
		chief.signForm(highRequirementForm);
		chief.signForm(lowRequirementForm);

		std::cout << GREEN << "\nTenative de signature formHight par intern: " << RESET << std::endl;
		intern.signForm(formHigh);
		intern.signForm(highRequirementForm);
		intern.signForm(lowRequirementForm);
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Une exception a été capturée: " << RESET << e.what() << std::endl;
	}
		// Création d'un formulaire avec des grades invalides
	try
	{
		Form invalidForm("ImpossibleForm", 0, 151);
	}
	catch (const Form::GradeTooHighException& e)
	{
		std::cerr << RED << "Form creation error: " << RESET << e.what() << std::endl;
	}
	// Signature d'un formulaire par un bureaucrate au seuil du grade requis
	try
	{
		Bureaucrat chief("Chief", 1);
		Bureaucrat intern("Intern", 150);
		Form formHigh("HighForm", 2, 5);

		Form edgeCaseForm("EdgeCaseForm", 150, 150);
		intern.signForm(edgeCaseForm);

		// Tentative de signature d'un formulaire déjà signé
		chief.signForm(formHigh);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Unexpected error: " << RESET << e.what() << std::endl;
	}
	return (0);
}
