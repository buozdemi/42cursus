/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:21:35 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/01 15:42:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);		
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		void	executeAction() const;
	private:
		ShrubberyCreationForm();
};

#endif