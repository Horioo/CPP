#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	private:
	std::string name;
	unsigned int hp;
	unsigned int ep;
	unsigned int ad;

	public:
	ClapTrap();
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap &operator=(const ClapTrap &copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif