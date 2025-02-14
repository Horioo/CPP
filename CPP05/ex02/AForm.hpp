#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

// Form gradeToSign = 75 (so pode assinar quem tiver 74 ou menos)

class Bureaucrat;

class AForm{

	private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExec;

	public:
	Form();
	Form(const std::string &name, int sign, int exec);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &copy);

	std::string getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int 		getGradeToExec() const;
	void		beSigned(const Bureaucrat &B);

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

};

std::ostream &operator<<(std::ostream &out, const Form &obj);

#endif