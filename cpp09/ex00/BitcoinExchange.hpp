/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:16:51 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/04 17:07:28 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib> // Pour utiliser exit correctement

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	//charge les données de prix à partir d'un fichier CSV
	bool loadPriceData(const std::string& filename);
	//Analyse une ligne d'entrée et extrait la date et la valeur
	bool parseLine(const std::string& line, std::string& date, float& value) const;
	//Calcule la valeur d'échange du Bitcoin pour un montant donné à une date spécifique
	float getExchangeValue(const std::string& date, float value) const;

private:
	std::map<std::string, float> dataBase; //stocke les données de prix du Bitcoin, indexées par date
};

#endif