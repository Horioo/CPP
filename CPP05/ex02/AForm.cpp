/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:08:15 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/14 22:16:23 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*			Constructors and Cannonical Form		*/
AForm::AForm() : name("Highest AForm"), isSigned(false), gradeToSign(1), gradeToExec(1){
	std::cout << "Default AForm Constructor" << std::endl;
}

AForm::AForm(const std::string &name, int sign, int exec) : name(name), isSigned(false), gradeToSign(sign), gradeToExec(exec){
	std::cout << "AForm Constructor with Data" << std::endl;
	if(this->gradeToSign < 1 || this->gradeToExec < 1)
		throw GradeTooHighException();
	else if(this->gradeToSign > 150 || this->gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::~AForm(){
	std::cout << "AForm shredder" << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec){
	std::cout << "AForm Copy Constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &copy){
	if(this != &copy)
	{
		std::cout << "AForm Copy Operator" << std::endl;
		this->isSigned = copy.isSigned;
	}
	return *this;
}

/*			Member Functions		*/

std::string AForm::getName() const{
	return this->name;
}

bool AForm::getIsSigned() const{
	return this->isSigned;
}

int AForm::getGradeToSign() const{
	return this->gradeToSign;
}

int AForm::getGradeToExec() const{
	return this->gradeToExec;
}

void AForm::beSigned(const Bureaucrat &B){
	if(this->isSigned)
	{
		std::cout << "AForm is already Signed" << std::endl;
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
std::ostream &operator<<(std::ostream &out, const AForm &obj){
	out << "AForm Name: " << obj.getName() << std::endl
	<< "AForm signed : " << (obj.getIsSigned() ? "Yes" : "No") << std::endl
	<< "AForm Grade To Sign : " << obj.getGradeToSign() << std::endl
	<< "AForm Grade To Exec : " <<  obj.getGradeToExec() << std::endl;
	return out;
}

/*		Exceptions */

AForm::GradeTooHighException::GradeTooHighException(){
}

AForm::GradeTooLowException::GradeTooLowException(){
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "AForm Grade is too High.";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "AForm Grade is too Low.";
}
