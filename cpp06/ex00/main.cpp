/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:50:26 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 20:09:05 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <scalar value 1> [<scalar value 2> ...]" << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; ++i)
	{
		std::cout << MAGENTA << "Converting '" << argv[i] << "':" << RESET << std::endl;
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl; // Ajoutez une ligne vide entre les conversions pour une meilleure lisibilité
	}
	return (0);
}
