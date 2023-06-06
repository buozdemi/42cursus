/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:24:46 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 17:48:13 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\n----TRY-CATCH TEST----"<< std::endl;
	try
	{
		Bureaucrat jimmy("Jimmy", 2);
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
        jimmy.decrementGrade();
        std::cout << "INFO:	" << jimmy << std::endl;
       jimmy.decrementGrade();
        std::cout << "INFO:	" << jimmy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n----TRY-CATCH TEST----"<< std::endl;
	try
	{
		Bureaucrat jimmy("Jimmy", 150);
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.decrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----TRY-CATCH TEST----"<< std::endl;
	try
	{
		Bureaucrat jimmy("Jimmy", 150);
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.setGrade(50);
		std::cout << "INFO:	" << jimmy << std::endl;
	 	jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
		jimmy.incrementGrade();
		std::cout << "INFO:	" << jimmy << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\n----CREATION TEST outside THE BLOCK----"<< std::endl;
	Bureaucrat Don("Don", 200);
	std::cout << "------------" <<std::endl;
	
	Bureaucrat unnamed_bureaucrat;
	std::cout << "INFO:	" << unnamed_bureaucrat << std::endl;
	std::cout << "------------" <<std::endl;
	
	Bureaucrat Jenny(unnamed_bureaucrat);
	std::cout << "INFO:	" << Jenny << std::endl;
	Jenny.setGrade(40);
	std::cout << "INFO:	" << Jenny << std::endl;
	std::cout << "------------" <<std::endl;
	
	Bureaucrat Kennedy;
	Kennedy = Jenny;
	std::cout << "INFO:	" << Kennedy << std::endl;
	Kennedy.setGrade(189);
	std::cout << std::endl;
	
	return 0;
}
