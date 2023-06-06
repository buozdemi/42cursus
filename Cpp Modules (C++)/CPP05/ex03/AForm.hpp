/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:22:13 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 15:54:09 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	const std::string target;
	bool sign;
	const int sign_grade;
	const int execute_grade;
public:
	AForm();
	AForm(const AForm& Form);
	AForm(const std::string& name, const std::string& target, int sign_grade, int execute_grade);
	virtual ~AForm();
	
	AForm& operator=(const AForm& other);
	
	const std::string	getName() const;
	const std::string	getTarget() const;
	bool				getSign() const;
	int 				getSignGrade() const;
	int 				getExecuteGrade() const;
	void 				setSign(bool sign);
	
	void	beSigned(const Bureaucrat &bureaucrat);
	void	execute(Bureaucrat const & executor) const;
	
	virtual void executeAction() const = 0;

	class NotSigned: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& my_cout, const AForm& other);

#endif