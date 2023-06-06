/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:42 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 15:56:03 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery creation", "none-target", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("shrubbery creation", target, 145, 137)
{
	std::cout << "Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade())
{
	setSign(other.getSign());
	std::cout << "Copy of Shrubbery Creation Form created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Shrubbery Creation Form assignment operator" << std::endl;
	if (this == &other)
		return *this;
	AForm::setSign(other.getSign());
	return (*this);
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream out;

	out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
	
	out << std::endl;
	out << "               ,@@@@@@@,                  " << std::endl;
	out << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	out << "    ,&&%&%&&%,@@@@@/@@@@@@,8888|88/8o     " << std::endl;
	out << "   ,%&|%&&%&&%,@@@|@@@/@@@88|88888/88'    " << std::endl;
	out << "   %&&%&%&/%&&%@@|@@/ /@@@88888|88888'    " << std::endl;
	out << "   %&&%/ %&&%&&@@| V /@@' `88|8 `/88'     " << std::endl;
	out << "   `&%| ` /%&'    |.|        | '|8'       " << std::endl;
	out << "       |o|        | |         | |         " << std::endl;
	out << "       |.|        | |         | |         " << std::endl;
	out << "    ||/ ._|//_/__/  ,|_//__||/.  |_//__/_ " << std::endl;
}