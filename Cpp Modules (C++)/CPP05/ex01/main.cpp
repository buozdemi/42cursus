/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:24:46 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/02 11:39:45 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n-------- BUREAUCRAT ---------\n" << std::endl;
	
	Bureaucrat bob("Bob", 2);
	try 
	{
		std::cout << "2: " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "1: " << bob << std::endl;
		bob.incrementGrade();
		std::cout << "This string shouldn't wrote: " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat michael("Michael", 148);
	try 
	{
		std::cout << "148: " << michael << std::endl;
		michael.decrementGrade();
		std::cout << "149: " << michael << std::endl;
		michael.decrementGrade();
		std::cout << "150: " << michael << std::endl;
		michael.decrementGrade();
		std::cout << "This string shouldn't wrote: " << michael << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	

	Bureaucrat lucy("Lucy", -1);
	std::cout << "Hello, I'm Lucy! " << lucy << std::endl;
	std::cout << std::endl;

	Bureaucrat gallagher("Gallagher", 151);
	std::cout << "Hello, I'm Gallagher! " << gallagher << std::endl;
	std::cout << std::endl;

	std::cout << "\n-------- FORM ---------\n" << std::endl;
	
	Bureaucrat poor("Poor", 130);
	Bureaucrat rich("Rich", 15);

	Form budgets("budgets", 30, 10);
	std::cout << std::endl;
	
	std::cout << "Budgets: " << budgets;
	std::cout << std::endl;

	std::cout << "-----poor&rich.signForm(budgets)-----" << std::endl;
	
	try
	{
		poor.signForm(budgets);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Must be not signed the budgets :" << budgets;
	std::cout << std::endl;

	try
	{
		rich.signForm(budgets);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	
	std::cout << "Must be signed the budgets : " << budgets;
	std::cout << std::endl;
	
	std::cout << "------budgets.beSigned(poor&rich)------\n" << std::endl;
	
	try
	{
		budgets.beSigned(poor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		budgets.beSigned(rich);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "---------Example already signed form---------" << std::endl;
	try
	{
		budgets.beSigned(poor);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;


	std::cout << "---------Last Try---------" << std::endl;
	Bureaucrat	Frank("Frank", 98);
	Form		formfood("formfood", 98, 74);
	try
	{
		Form	formshop("formshop", 65, 65);
		std::cout << formshop << std::endl;
		Frank.signForm(formfood);
		Bureaucrat Joe("Joe", 200);
		Frank.signForm(formshop);
		formshop.beSigned(Frank);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return(0);
}
