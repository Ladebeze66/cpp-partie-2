/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:28:49 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/11 14:08:26 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade(); // Devrait lancer une exception
	}
	catch (const std::exception& e)
	{
		std::cerr<< RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat jim("Jim", 149);
		std::cout << jim << std::endl;
		jim.decrementGrade();
		std::cout << jim << std::endl;
		jim.decrementGrade(); // Devrait lancer une exception
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
