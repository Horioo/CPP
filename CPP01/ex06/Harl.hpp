/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:54:21 by ajorge-p          #+#    #+#             */
/*   Updated: 2024/10/10 10:55:01 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	
	public:
	Harl();
	~Harl();
	std::string levels[4];
	void (Harl::*func[4])(void);
	void complain(int i);
	int assignNumber(std::string arg);
	
	private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif