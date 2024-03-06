/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:13:10 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/06 15:44:07 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main()
{
	RPNCalculator calculator;

	std::cout << ORANGE << "Enter RPN expressions (or 'exit' to quit):" << RESET << std::endl;
	
	std::string expression;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, expression);
		
		if (expression == "exit")
		{
			break; // Sortir de la boucle si l'utilisateur entre 'exit'
		}

		try
		{
			float result = calculator.evaluateExpression(expression);
			std::cout << GREEN << "Result: " << RESET << result << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}
	return (0);
}
