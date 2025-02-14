#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
	
	private:
	const std::string name;
	int grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);


	std::string getName() const;
	int			getGrade() const;
	void		addGrade();
	void		lowerGrade();
	void 		signForm(Form &F);

	class GradeTooHighException : public std::exception {
		public:
			explicit GradeTooHighException();
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			explicit GradeTooLowException();
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);

#endif