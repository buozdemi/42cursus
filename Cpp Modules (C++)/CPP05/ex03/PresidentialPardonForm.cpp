/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:19:58 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 15:51:03 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", "none-target", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("presidential pardon", target, 25, 5)
{
	std::cout << "Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm(other.getName(), other.getTarget(), other.getSignGrade(), other.getExecuteGrade())
{
	setSign(other.getSign());
	std::cout << "Copy of Presidential Pardon Form created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Presidential Pardon Form assignment operator" << std::endl;
	if (this == &other)
		return *this;
	AForm::setSign(other.getSign());
	return (*this);
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}