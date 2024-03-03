/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:14:40 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/03 15:10:40 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template<typename T>
void easyfind(T& container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
	{
		std::cout << RED << "Not found." << RESET << std::endl;
	}
	else
	{
		std::cout << GREEN << "Found at position: " << RESET << std::distance(container.begin(), it) << std::endl;
	}
}

#endif