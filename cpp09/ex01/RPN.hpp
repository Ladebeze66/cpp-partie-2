/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:49:08 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/06 15:42:36 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cmath>

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"
#define ORANGE	"\033[38;5;214m"

class RPNCalculator
{
public:
	RPNCalculator();
	~RPNCalculator();
	RPNCalculator(const RPNCalculator& other);
	RPNCalculator& operator=(const RPNCalculator& other);

	float evaluateExpression(const std::string& expression);

private:
	std::stack<float> stack;
	void processToken(const std::string& token);
};

#endif