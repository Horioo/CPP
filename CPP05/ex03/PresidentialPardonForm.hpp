#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

	private:
	std::string target;

	public:
	PresidentialPardonForm(std::string target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm& copy);

	std::string getTarget() const;
	int execute(Bureaucrat const & executor) const;
};

#endif