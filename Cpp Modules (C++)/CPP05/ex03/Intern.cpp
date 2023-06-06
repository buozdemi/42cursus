/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:54:39 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 16:02:37 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assignment operator" << std::endl;
	if (this == &other)
		return *this;
	return (*this);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *form = NULL;
	int index = -1;
	enum temp {presidential, robotomy, shrubbery};
	std::string names[3] = {"presidential", "robotomy", "shrubbery"};

	while (++index < 4)
		if (name == names[index])
			break ;
	switch (index)
	{
		case presidential:
			std::cout << "Intern creates presidential" << std::endl;
			return (new PresidentialPardonForm(target));
		case robotomy:
			std::cout << "Intern creates robotomy" << std::endl;
			return (new RobotomyRequestForm(target));
		case shrubbery:
			std::cout << "Intern creates shrubbery" << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern cannot create the form" << std::endl;
			break ;	
	}
	return (form);
}

std::ostream&	operator<<(std::ostream& my_cout, const Intern& right)
{
	(void)right;
	my_cout << "Hey! I'm an intern!" << std::endl;
	return (my_cout);
}