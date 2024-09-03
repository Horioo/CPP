#include "Zombie.hpp"

int main(){

	Zombie Z1;
	Zombie *Z2 = newZombie("Alberto");

	std::cout << "Zombie name = " << Z1.getName() << std::endl;
	std::cout << "Zombie name = " << Z2->getName() << std::endl;

	randomChump("Trigonometria");
	delete Z2;
}