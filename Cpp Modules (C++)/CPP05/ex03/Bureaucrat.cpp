/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:23:54 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 12:11:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("unnamed")
{
	//std::cout << "[Bureaucrat-Default]	constructor called" << std::endl;
	this->grade = 75;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name)
{
	//std::cout << "[Bureaucrat-Overloaded]	constructor called" << std::endl;
	this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName())
{
	//std::cout << "[Bureaucrat-Copy constructor]	called" << std::endl;
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	//std::cout << "[Bureaucrat-Copy assignment]	operator called" << std::endl;
	if (this != &other)
		this->grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureucrat-Destructor]	called for " << this->name  << std::endl;
}

void	Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		this->grade = 75;
	}
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}
		
int	Bureaucrat::getGrade() const
{
	return (this->grade);
}
		
void	Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}
		
void	Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream& operator<<(std::ostream &my_cout, const Bureaucrat &right)
{
	my_cout << right.getName() << ", bureaucrat grade " << right.getGrade() << ".";
	return(my_cout);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\033[31mBureaucrat grade is too high!\033[0m";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\033[31mBureaucrat grade is too low!\033[0m";
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " could not sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}