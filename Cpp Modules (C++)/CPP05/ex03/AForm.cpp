/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:22:29 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 17:30:36 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	name("basic_form"),
	sign(false),
	sign_grade(150),
	execute_grade(150)
{
	//std::cout << "[Form-Default]	constructer called." << std::endl;
}

AForm::AForm(const AForm& other):
	name(other.name),
	sign_grade(other.sign_grade),
	execute_grade(other.execute_grade)
{
	sign = other.sign;
	//std::cout << "[Form-Copy constructor]	called" << std::endl;
}

AForm::AForm(const std::string& name, const std::string& target, int sign_grade, int execute_grade):
	name(name), 
	target(target),
	sign(false),
	sign_grade(sign_grade), 
	execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	else if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	//std::cout << "[Form-Overloaded]	constructor called " << std::endl;
}

AForm::~AForm()
{
	std::cout << "[Form-Destructor]	called for " << this->name  << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->sign = other.sign;
	//std::cout << "[Form-Copy assignment]	operator called" << std::endl;
	return (*this);
}

const std::string AForm::getName() const
{
	return (this->name);
}

const std::string AForm::getTarget() const
{
	return (this->target);
}

bool AForm::getSign() const
{
	return (this->sign);
}

int	AForm::getSignGrade() const
{
	return (this->sign_grade);
}

int	AForm::getExecuteGrade() const
{
	return (this->execute_grade);
}

void AForm::setSign(bool sign)
{
	this->sign = sign;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if ((bureaucrat.getGrade() <= this->getSignGrade()) && this->getSign() == false)
	{
		this->sign = true;
	}
	else if ((bureaucrat.getGrade() > this->getSignGrade()))
	{
		throw GradeTooHighException();
	}
}

std::ostream& operator<<(std::ostream &my_cout, const AForm& other)
{
	my_cout << "Form " << other.getName()
	<< ", status: " << (other.getSign() ? "signed" : "not signed")
	<< ", sign grade: " << other.getSignGrade()
	<< ", execute grade: " << other.getExecuteGrade();
	
	return (my_cout);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "\033[31mForm grade is too high!\033[0m";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "\033[31mForm grade is too low!\033[0m";
}

const char* AForm::NotSigned::what() const throw() {
	return "Exception: form is not signed so it can't be executed";
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if(this->sign == false)
	{
		std::cout << executor.getName() << " can't execute " << this->name << " because ";
		throw AForm::NotSigned();
	}
	if (executor.getGrade() > this->execute_grade)
	{
		std::cout << executor.getName() << " can't execute " << this->name << " because ";
		throw AForm::GradeTooLowException();
	}

	std::cout << executor.getName() << " executed " << this->name << std::endl;
	this->executeAction();
}
