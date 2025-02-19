#ifndef SHRUBBERY_CREATION_FROM_HPP
#define SHRUBBERY_CREATION_FROM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{

	private:
	std::string target;

	public:
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm& copy);

	std::string getTarget() const;
	int execute(Bureaucrat const & executor) const;
};

#endif