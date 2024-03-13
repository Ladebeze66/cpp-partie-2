/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:20:25 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/13 13:19:00 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << GREEN << "Default constructor Span called!" << RESET << std::endl;
} 

Span::Span(unsigned int N): capacity(N)
{
	std::cout << GREEN << "Span constructor called!" << RESET << std::endl;
}

Span::Span(const Span& other): numbers(other.numbers), capacity(other.capacity)
{
	std::cout << CYAN << "Copy constructor called for Span." << RESET << std::endl;
}

Span& Span::operator=(const Span& other)
{
	std::cout << YELLOW << "Copy assignment Span operator called" << RESET << std::endl;
	if (this != &other)
	{
		numbers = other.numbers;
		capacity = other.capacity;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << RED << "Span is destroyed!" << RESET << std::endl;
}

void Span::addNumber(int number)
{
	if (numbers.size() >= capacity)
		throw std::length_error("Span is full.");
	numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough elements for span.");
	std::sort(numbers.begin(), numbers.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < numbers.size(); ++i)
	{
		int span = numbers[i] - numbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough elements for span.");

	// Utilisation de std::min_element et std::max_element séparément
	std::vector<int>::iterator minIt = std::min_element(numbers.begin(), numbers.end());
	std::vector<int>::iterator maxIt = std::max_element(numbers.begin(), numbers.end());

	// Calcul de la span la plus longue
	return (*maxIt - *minIt);
}

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}