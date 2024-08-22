#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {

	public:
	PhoneBook(void);
	~PhoneBook(void);
	int c_index;
	int max_index;

	void AddContact(void);
	void SearchContact(void);
	void ExitProgram(void);
	void PrintList(int i);
	void PrintInfo(int i);

	private:
	Contact contact[8];

};

#endif

