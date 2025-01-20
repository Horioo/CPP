#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap{

	private:
	std::string name;
	using FragTrap::hp;
	using ScavTrap::ep;
	using FragTrap::ad;

	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void whoAmI(); 
	std::string getRealName();
};

#endif