#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{

	private:
	std::string target;

	public:
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& copy);

	std::string getTarget() const;
	int execute(Bureaucrat const & executor) const;
};


#endif