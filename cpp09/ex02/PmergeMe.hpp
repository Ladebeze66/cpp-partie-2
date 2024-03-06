/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:17:28 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/03/06 17:18:48 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);

	void sortAndDisplay(const std::vector<int>& input);
	void sortAndDisplay(const std::list<int>& input);

private:
	template<typename Container>
	void forJohnsonSort(Container& container);

	template<typename Container>
	void displaySequence(const Container& sequence, const std::string& prefix);

	template<typename Container>
	void mesureAndSort(Container& container);
};

#endif