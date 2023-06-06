/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:20:44 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/27 19:16:13 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("robotomy request", "none-target", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("robotomy request", target, 72, 45)
{
	std::cout << "Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade())
{
	setSign(other.getSign());
	std::cout << "Copy of Robotomy Request Form created" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Robotomy Request Form assignment operator" << std::endl;
	if (this == &other)
		return *this;
	AForm::setSign(other.getSign());	
	return (*this);
}

void	RobotomyRequestForm::executeAction() const
{
	std::srand(std::time(NULL));
	std::cout << "Brong, brong, brong..." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Failed to robotomized " << this->getTarget() << std::endl;
}