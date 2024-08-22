#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {

	public:
	PhoneBook(void);
	~PhoneBook(void);
	int c_index;

	void AddContact(void);
	void SearchContact(void);
	void ExitProgram(void);

	private:
	Contact contact[8];

};

#endif

