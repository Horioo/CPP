/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajorge-p <ajorge-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:19:02 by ajorge-p          #+#    #+#             */
/*   Updated: 2025/02/19 13:11:01 by ajorge-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150){
	std::cout << "Default Constructor for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade){
	std::cout << "Constructor with Name and Grade for Bureaucrat" << std::endl;
	if(this->grade < 1)
		throw GradeTooHighException();
	else if(this->grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat Destroyer" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade){
	std::cout << "Bureaucrat Copy Constructor" << std::endl;
}

//Não é possivel fazer a copia do this->name visto ser um atributo const 
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy){
	if(this != &copy)
	{
		std::cout << "Bureaucrat Copy Operator" << std::endl;
		this->grade = copy.grade;
	}
	return *this;
}

/*				Member Functions*/

std::string Bureaucrat::getName() const{
	return this->name;
}

int Bureaucrat::getGrade() const{
	return this->grade;
}

void Bureaucrat::addGrade(){
	if(this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::lowerGrade(){
	if(this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm &F){
	std::cout << this->name << " trying to Sign form " << F.getName() << std::endl; 
	F.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form){
	std::cout << this->name << " is Trying to Execute " << form.getName() << std::endl; 
	if(form.execute(*this) == 1){
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	else
		std::cout << "Clearly the Bureaucrat cant sign this because something is wrong, find it and solve it :-D" << std::endl;
}


/*				Operator overload*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj){
	out << obj.getName() << " bureaucrat grade " << obj.getGrade() << std::endl;
	return out;
}

/*				Exceptions Constructor and what()*/

Bureaucrat::GradeTooHighException::GradeTooHighException(){
}

Bureaucrat::GradeTooLowException::GradeTooLowException(){
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat Grade is too High.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat Grade is too Low.";
}
