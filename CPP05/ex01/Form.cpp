/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:08:15 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/14 21:54:11 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*			Constructors and Cannonical Form		*/
Form::Form() : name("Highest Form"), isSigned(false), gradeToSign(1), gradeToExec(1){
	std::cout << "Default Form Constructor" << std::endl;
}

Form::Form(const std::string &name, int sign, int exec) : name(name), isSigned(false), gradeToSign(sign), gradeToExec(exec){
	std::cout << "Form Constructor with Data" << std::endl;
	if(this->gradeToSign < 1 || this->gradeToExec < 1)
		throw GradeTooHighException();
	else if(this->gradeToSign > 150 || this->gradeToExec > 150)
		throw GradeTooLowException();
}

Form::~Form(){
	std::cout << "Form shredder" << std::endl;
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){
	std::cout << "Form Copy Constructor" << std::endl;
}

Form &Form::operator=(const Form &copy){
	if(this != &copy)
	{
		std::cout << "Form Copy Operator" << std::endl;
		this->isSigned = copy.isSigned;
	}
	return *this;
}

/*			Member Functions		*/

std::string Form::getName() const{
	return this->name;
}

bool Form::getIsSigned() const{
	return this->isSigned;
}

int Form::getGradeToSign() const{
	return this->gradeToSign;
}

int Form::getGradeToExec() const{
	return this->gradeToExec;
}

void Form::beSigned(const Bureaucrat &B){
	if(this->isSigned)
	{
		std::cout << "Form is already Signed" << std::endl;
		return ;
	}
	if(B.getGrade() > this->gradeToSign){
		std::cout << B.getName() << " couldn't sign " << this->name << " because grade is to Low" << std::endl;
		throw GradeTooLowException();
	}
	else{
		std::cout << B.getName() << " Signed " << this->name << std::endl;
		this->isSigned = true;
	}
}

/*		Operator Overload		*/
std::ostream &operator<<(std::ostream &out, const Form &obj){
	out << "Form Name: " << obj.getName() << std::endl
	<< "Form signed : " << (obj.getIsSigned() ? "Yes" : "No") << std::endl
	<< "Form Grade To Sign : " << obj.getGradeToSign() << std::endl
	<< "Form Grade To Exec : " <<  obj.getGradeToExec() << std::endl;
	return out;
}

/*		Exceptions */

Form::GradeTooHighException::GradeTooHighException(){
}

Form::GradeTooLowException::GradeTooLowException(){
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Form Grade is too High.";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Form Grade is too Low.";
}
