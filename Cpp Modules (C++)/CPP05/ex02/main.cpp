/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:33:11 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 12:02:12 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b150("b150", 150);
	Bureaucrat b140("b140", 140);
	Bureaucrat b100("b100", 100);
	Bureaucrat b1("b1", 1);

	std::cout << std::endl;

	std::cout << b150 << std::endl;
	std::cout << b140 << std::endl;
	std::cout << b100 << std::endl;
	std::cout << b1 << std::endl;

	std::cout << std::endl;

	ShrubberyCreationForm garden("garden");
	RobotomyRequestForm neighbor("neighbor");
	PresidentialPardonForm rick("rick");

	std::cout << std::endl;

	std::cout << garden << std::endl;
	std::cout << neighbor << std::endl;
	std::cout << rick << std::endl;

	std::cout << std::endl;
	
	// ShrubberyCreationForm
	try{ // try to execute before sign
		b100.executeForm(garden);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{ // try to sign with low level. (Shrubbery: 145)
		b150.signForm(garden);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{ // sign 
		b140.signForm(garden);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << garden << std::endl; // display update info, sign should be YES.
	try{ // try to execute with low level
		b140.executeForm(garden);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{ // execute OK, because 100 level.
		b100.executeForm(garden);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	
	//RobotomyRequestForm (execute main multiple times to check randomizer is working)
	try { // sign
		b1.signForm(neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try { // execute
		b1.executeForm(neighbor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	// PresidentialPardonForm
	try { //sign
		b1.signForm(rick);
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try { //execute
		b1.executeForm(rick);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	//Copy constructor form example: Copy that already signed form
	Bureaucrat osman("osman", 1);
	ShrubberyCreationForm a("my_target");
	osman.signForm(a);
	ShrubberyCreationForm b(a);
	osman.signForm(b);
	
	std::cout << std::endl;
	return (0);
}
