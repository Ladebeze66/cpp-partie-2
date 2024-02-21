/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:56:48 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/21 15:17:46 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define GREEN	"\033[32m"
#define CYAN	"\033[36m"
#define RED		"\033[31m"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const &executor) const override;
	std::string getTarget() const;
};

#endif
