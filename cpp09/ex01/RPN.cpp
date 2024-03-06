/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:04:53 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/06 15:40:51 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPNCalculator::RPNCalculator()
{
	// Le constructeur par défaut reste inchangé.
}

RPNCalculator::~RPNCalculator()
{
	// Le destructeur reste inchangé.
}

RPNCalculator::RPNCalculator(const RPNCalculator& other) : stack(other.stack)
{
	// Le constructeur de copie reste inchangé.
}

RPNCalculator& RPNCalculator::operator=(const RPNCalculator& other)
{
	if (this != &other)
	{
		this->stack = other.stack;
	}
	return (*this);
}

float RPNCalculator::evaluateExpression(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	stack = std::stack<float>(); // Réinitialisez la pile avant de traiter une nouvelle expression

	while (iss >> token)
	{
		processToken(token);
	}

	if (stack.size() != 1)
	{
		throw std::runtime_error("Error: Invalid RPN expression.");
	}
	float result = stack.top(); // Stockez le résultat final avant de vider la pile
	stack.pop(); // Assurez-vous que la pile est vide après avoir récupéré le résultat

	return (result);
}

void RPNCalculator::processToken(const std::string& token)
{
	if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
	{
		std::istringstream iss(token);
		float number;
		iss >> number;

		// Vérifie si le nombre est strictement inférieur à 10
		if (std::abs(number) >= 10)
		{
			throw std::runtime_error("Error: Numbers used must always be less than 10.");
		}

		stack.push(number);
	}
	else
	{
		if (stack.size() < 2) throw std::runtime_error("Error: Not enough operands.");

		float operand2 = stack.top(); stack.pop();
		float operand1 = stack.top(); stack.pop();

		switch (token[0]) {
			case '+': stack.push(operand1 + operand2); break;
			case '-': stack.push(operand1 - operand2); break;
			case '*': stack.push(operand1 * operand2); break;
			case '/':
				if (operand2 == 0) throw std::runtime_error("Error: Division by zero.");
				stack.push(operand1 / operand2);
				break;
			default: throw std::runtime_error("Error: Invalid operator.");
		}
	}
}
