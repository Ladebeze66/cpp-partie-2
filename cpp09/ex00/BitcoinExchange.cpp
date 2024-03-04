/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:56:17 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/04 16:52:42 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN << "BitcoinExchange default constructor called!" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : dataBase(other.dataBase)
{
	std::cout << CYAN << "Copy constructor called for BitcoinExchange " << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << YELLOW << "Copy assignment BitcoinExchange operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->dataBase = other.dataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange is destroyed!" << RESET << std::endl;
}
//charge les fichiers à partir d'un fichier CSV
bool BitcoinExchange::loadPriceData(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open price data file." << std::endl;
		return false;
	}
	
	std::string line;
	// Ignorer la première ligne (en-têtes)
	std::getline(file, line);

	std::string date;
	float exchangeRate;
	while (getline(file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ',') && (iss >> exchangeRate))
		{
			dataBase[date] = exchangeRate;
		}
		else
		{
			std::cerr << "Warning: Malformed line skipped -> " << line << std::endl;
		}
	}
	
	file.close();
	// Optionnel: afficher les données chargées pour vérification
	
	/*for (std::map<std::string, float>::const_iterator it = dataBase.begin(); it != dataBase.end(); ++it)
	{
		std::cout << "Date: " << it->first << ", Exchange Rate: " << it->second << std::endl;
	}*/
	return (true);
}
//Analyse une ligne d'entrée et extrait la date et la valeur
bool BitcoinExchange::parseLine(const std::string& line, std::string& date, float& value) const
{
	std::istringstream iss(line);
	std::string valueStr;
	std::getline(iss, date, '|'); // Extrait la date jusqu'au délimiteur '|'.
	
	// Supprime les espaces en début et en fin de 'date'.
	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_last_not_of(" \t") + 1);

	std::getline(iss, valueStr); // Extrait le reste de la ligne comme 'valueStr'.
	valueStr.erase(0, valueStr.find_first_not_of(" \t")); // Supprime les espaces en début de 'valueStr'.

	std::istringstream valueStream(valueStr); // Crée un istringstream basé sur 'valueStr' pour la conversion.
	if (!(valueStream >> value) || valueStream.peek() != EOF)
	{ // Vérifie la conversion et s'assure qu'il n'y a pas de caractères supplémentaires.
		return (false);
	}
	
	return (true);
}
//Calcule la valeur d'échange du Bitcoin pour un montant donné à une date spécifique
float BitcoinExchange::getExchangeValue(const std::string& date, float value) const
{
	std::map<std::string, float>::const_iterator it = dataBase.find(date);
	if (it != dataBase.end())
	{
		// Si la date exacte est trouvée dans la base de données
		return (it->second * value);
	}
	else
	{
		// Recherche de la date la plus proche inférieure
		// std::map::lower_bound retourne un itérateur pointant vers la première clé qui n'est pas inférieure à 'date'
		// On utilise donc std::prev pour reculer d'une position si l'itérateur n'est pas au début
		std::map<std::string, float>::const_iterator closest = dataBase.lower_bound(date);
		if (closest == dataBase.begin())
		{
			// Si 'closest' est au début, il n'y a pas de date antérieure disponible
			return (-1.0); // Indique une erreur ou une date non trouvée
		}
		else
		{
			// Reculer d'une position pour trouver la date antérieure la plus proche
			--closest;
			return(closest->second * value);
		}
	}
}
