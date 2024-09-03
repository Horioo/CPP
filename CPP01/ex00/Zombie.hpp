#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

	public:

	//Zombie(void);
	//~Zombie(void);
	void announce(void);
	void setName(std::string name);
	std::string getName(void);

	private:
	std::string name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif