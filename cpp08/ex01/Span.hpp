/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:53:40 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 16:49:04 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>
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

class Span
{
public:
	Span(unsigned int N);				//constructor
	Span(const Span& other);			//copy constructor
	Span& operator=(const Span& other);	//operateur d'assignation
	~Span();							//destructor

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	template<typename Iterator>
	void addRange(Iterator begin, Iterator end);

private:
	std::vector<int> numbers;
	unsigned int capacity;
};

#endif