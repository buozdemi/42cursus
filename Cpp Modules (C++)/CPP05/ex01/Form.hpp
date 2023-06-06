/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:37:42 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/28 20:19:29 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool sign;
		const int sign_grade;
		const int execute_grade;
	public:
		Form();
		Form(const Form& Form);
		Form(const std::string& name, int sign_grade, int execute_grade);
		~Form();
		
		Form& operator=(const Form& other);
		
		const std::string	getName() const;
		bool				getSign() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		
		void				beSigned(const Bureaucrat &bureaucrat);
		
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

std::ostream& operator<<(std::ostream& my_cout, const Form& other);

#endif