/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:58:04 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/27 13:41:15 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

#define RESET	"\033[0m"
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

class Serializer
{
public:
	// Méthodes statiques publiques pour la sérialisation et la désérialisation
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	// Constructeur par défaut privé pour empêcher l'instanciation
	Serializer();
	// Constructeur de copie privé pour empêcher la copie
	Serializer(const Serializer&);
	// Opérateur d'affectation privé pour empêcher l'affectation
	Serializer& operator=(const Serializer&);
	// Destructeur privé
	~Serializer();
};

#endif
