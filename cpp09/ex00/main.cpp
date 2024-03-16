/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:09:27 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/16 13:37:43 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./btc <input_file>" << RESET << std::endl;
		exit(1);
	}

	std::string inputFile = argv[1];
	std::ifstream input(inputFile.c_str());
	if (!input.is_open())
	{
		std::cerr << RED << "Error: could not open " << RESET << inputFile << std::endl;
		exit(1);
	}

	// Ignorer la première ligne
	std::string header;
	getline(input, header);

	BitcoinExchange exchange;
	std::string priceDataFile = "data.csv";
	if (!exchange.loadPriceData(priceDataFile))
	{
		std::cerr << RED << "Error loading price data from " << RESET << priceDataFile << std::endl;
		exit(1);
	}
	std::string line;
	while (getline(input, line))
	{
		std::string date;
		float amount;
		// Analyse la ligne pour extraire la date et la valeur
		if (exchange.parseLine(line, date, amount))
		{
			// Vérifie que la valeur est dans la plage [0, 1000]
			if (amount < 0)
			{
				std::cout << RED << "Error: not a positive number." << RESET << std::endl;
				continue; // Passe à la ligne suivante si la valeur est hors plage
			}
			else if (amount > 1000)
			{
				std::cout << RED << "Error: too large a number." << RESET << std::endl;
				continue; // Passe à la ligne suivante si la valeur est hors plage
			}
			// Calcule la valeur d'échange du Bitcoin pour la date et le montant donnés
			float exchangeValue = exchange.getExchangeValue(date, amount);
			if (exchangeValue >= 0)
			{
				std::cout << YELLOW << date << " => " << RESET << amount << " = " << GREEN << exchangeValue << RESET << std::endl;
			}
			else
			{
				std::cout << RED << "Error: Date " << RESET  << date << " not found in the price database." << std::endl;
			}
		}
		else
		{
			std::cerr << RED << "Error: bad input => " << RESET << line << std::endl;
		}
	}
	return (0);
}
