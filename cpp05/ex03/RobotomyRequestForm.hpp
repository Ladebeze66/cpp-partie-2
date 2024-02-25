/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:55:26 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/22 16:10:22 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib> // Pour std::rand() et std::srand()
#include <ctime> // Pour std::time()

// Assurez-vous d'avoir ces définitions quelque part, ou remplacez-les par vos propres codes de couleur.
#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"
#define RED		"\033[31m"
class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();
	static void initializeRandomSeed();

	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;
};

#endif
