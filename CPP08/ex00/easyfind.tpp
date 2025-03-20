/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:40:53 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/03/19 11:58:00 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator i = std::find(container.begin(), container.end(), find);
	if(i == container.end())
		throw std::runtime_error("Can't find the value on the container");
	return i;
}

