/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:19:14 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 20:00:56 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iomanip>

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class ScalarConverter
{
public:
	static void convert(const std::string& literal);
	~ScalarConverter();

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter& operator=(const ScalarConverter&);

	static char convertToChar(double num);
	static int convertToInt(double num);
	static float convertToFloat(double num);
	static double convertToDouble(const std::string& literal);
	static void printAsChar(char c);
	static void printAsInt(int i);
	static void printAsFloat(float f);
	static void printAsDouble(double d);

};

#endif