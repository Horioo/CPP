#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>

// Form gradeToSign = 75 (so pode assinar quem tiver 74 ou menos)

class Bureaucrat;

class AForm{

	private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

	public:
	AForm();
	AForm(const std::string &name, int sign, int exec);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &copy);

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int 		getGradeToExec() const;
	void		beSigned(const Bureaucrat &B);

	virtual int		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception{
		public:
			explicit GradeTooHighException();
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception{
		public:
			explicit GradeTooLowException();
			const char* what() const throw();
	};

	class NotSignedException : public std::exception{
		public:
			explicit NotSignedException();
			const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const AForm &obj);

#endif