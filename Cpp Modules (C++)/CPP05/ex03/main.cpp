/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:33:11 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 16:19:19 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	Bureaucrat supervisor("Supervisor", 1);
	Bureaucrat francis("Francis", 25);

	AForm *shrub = someRandomIntern.makeForm("shrubbery", "home");
	supervisor.signForm(*shrub);
	shrub->execute(francis);

	std::cout << "---------------" << std::endl;
	AForm *pres = someRandomIntern.makeForm("presidential", "Francis");
	supervisor.signForm(*pres);
	pres->execute(supervisor);

	std::cout << "---------------" << std::endl;
	AForm *robot = someRandomIntern.makeForm("robotomy", "Bender");
	supervisor.signForm(*robot);
	robot->execute(francis);
	
	francis.executeForm(*robot);
	francis.executeForm(*robot);

	std::cout << "---------------" << std::endl;
	try
	{
		AForm *fake = someRandomIntern.makeForm("fake request", "Bender");
		delete fake;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;
	return (0);
}
