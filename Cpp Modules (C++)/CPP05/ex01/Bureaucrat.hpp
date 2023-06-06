/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoner <aoner@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:54:51 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/28 20:19:06 by aoner            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat &other);
		
		~Bureaucrat();
		
		Bureaucrat&			operator=(const Bureaucrat& other);
		
		virtual std::string	getName() const;
		virtual int			getGrade() const;
		void				setGrade(int grade);
		
		void				incrementGrade();
		void				decrementGrade();
		
		void				signForm(Form& form);
		
		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &my_cout, const Bureaucrat &right);

#endif