/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:00:38 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/26 16:04:34 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructeur privé
Serializer::Serializer()
{}
// Constructeur de copie privé
Serializer::Serializer(const Serializer&)
{
	// Généralement vide car la classe ne doit pas être copiée.
}
// Opérateur d'affectation privé
Serializer& Serializer::operator=(const Serializer&)
{    // Généralement vide car l'affectation ne doit pas être effectuée.
	return (*this);
}
// Destructeur privé
Serializer::~Serializer()
{
	// Généralement vide car la classe ne doit pas être instanciée.
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}