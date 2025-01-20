#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	protected:
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

	virtual void attack(const std::string& target);
	virtual void takeDamage(unsigned int amount);
	virtual void beRepaired(unsigned int amount);
	std::string getName();
};

#endif