/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:53 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/16 15:46:23 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPNCalculator::RPNCalculator()
{
	std::cout << GREEN << "RPNCalculator default constructor called!" << RESET << std::endl;
}

RPNCalculator::~RPNCalculator()
{
	std::cout << RED << "RPNCalculator is destroyed!" << RESET << std::endl;
}

RPNCalculator::RPNCalculator(const RPNCalculator& other) : stack(other.stack)
{
	std::cout << CYAN << "Copy constructor called for RPNCalculator." << RESET << std::endl;
}

RPNCalculator& RPNCalculator::operator=(const RPNCalculator& other)
{
	std::cout << YELLOW << "Copy assignment RPNCalculator operator called." << RESET << std::endl;
	if (this != &other)
	{
		this->stack = other.stack;
	}
	return (*this);
}

int RPNCalculator::evaluateExpression(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	stack = std::stack<int>(); // Réinitialisez la pile avant de traiter une nouvelle expression

	while (iss >> token)
	{
		processToken(token);
	}

	if (stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid RPN expression.");
	}
	int result = stack.top(); // Stockez le résultat final avant de vider la pile
	stack.pop(); // Assurez-vous que la pile est vide après avoir récupéré le résultat

	return (result);
}

void RPNCalculator::processToken(const std::string& token)
{
	// Vérifier la présence de parenthèses dans le token
	if (token.find('(') != std::string::npos || token.find(')') != std::string::npos)
	{
		throw std::runtime_error("Error: Parentheses are not handled.");
	}

	if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
	{
		std::istringstream iss(token);
		float number; // Utilisez float pour lire le nombre, cela permet de capturer les décimaux
		iss >> number;
		// Vérifiez si le nombre est décimal en comparant à sa version arrondie
		if (number != std::floor(number))
		{
			throw std::runtime_error("Error: Decimal numbers are not handled.");
		}
		// Convertissez le nombre en int pour les opérations ultérieures
		int intNumber = static_cast<int>(number);
		// Vérifiez si le nombre est strictement inférieur à 10
		if (std::abs(intNumber) >= 10)
		{
			throw std::runtime_error("Error: Numbers used must always be less than 10.");
		}
		stack.push(intNumber);
	}
	else
	{
		if (stack.size() < 2)
		{
			throw std::runtime_error("Error: Not enough operands.");
		}

		int operand2 = stack.top(); stack.pop();
		int operand1 = stack.top(); stack.pop();

		switch (token[0])
		{
			case '+': stack.push(operand1 + operand2); break;
			case '-': stack.push(operand1 - operand2); break;
			case '*': stack.push(operand1 * operand2); break;
			case '/':
				if (operand2 == 0)
				{
					throw std::runtime_error("Error: Division by zero.");
				}
				stack.push(operand1 / operand2);
				break;
			default: throw std::runtime_error("Error: Invalid operator.");
		}
	}
}
