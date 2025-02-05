#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {

	public:

	Zombie(void);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
	std::string getName(void);

	private:
	std::string name;

};

Zombie* zombieHorde( int N, std::string name );

#endif