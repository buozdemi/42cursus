/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:37:35 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 16:34:24 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	name("basic_form"),
	sign(false),
	sign_grade(150),
	execute_grade(150)
{
	//std::cout << "[Form-Default]	constructer called." << std::endl;
}

Form::Form(const Form& other):
	name(other.name),
	sign_grade(other.sign_grade),
	execute_grade(other.execute_grade)
{
	sign = other.sign;
	//std::cout << "[Form-Copy constructor]	called" << std::endl;
}

Form::Form(const std::string& name, int sign_grade, int execute_grade):
	name(name), 
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

Form::~Form()
{
	std::cout << "[Form-Destructor]	called for " << this->name  << std::endl;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->sign = other.sign;
	//std::cout << "[Form-Copy assignment]	operator called" << std::endl;
	return (*this);
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecuteGrade() const
{
	return (this->execute_grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
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

std::ostream& operator<<(std::ostream &my_cout, const Form& other)
{
	my_cout << "Form " << other.getName()
	<< ", status: " << (other.getSign() ? "signed" : "not signed")
	<< ", sign grade: " << other.getSignGrade()
	<< ", execute grade: " << other.getExecuteGrade();
	
	return (my_cout);
}

const char* Form::GradeTooHighException::what() const throw() {
	return "\033[31mForm grade is too high!\033[0m";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "\033[31mForm grade is too low!\033[0m";
}
