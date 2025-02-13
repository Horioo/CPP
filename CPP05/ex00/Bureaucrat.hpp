#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>


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

	// O what() é um metodo herdado 
	// da class std::exception que esta como virtual
	// Por isso vamos rescrevê-lo
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