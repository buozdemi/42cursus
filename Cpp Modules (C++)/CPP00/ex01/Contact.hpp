/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:20:54 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:21:44 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdio>

class Contact {
	int i;
	std::string data[5];
public:
	Contact() : i(0) {}
	void		setData(std::string data);
	std::string getData(int i);
	int 		is_full_data();
	int			is_digit();
	void 		fill_name();
	void 		fill_lastname();
	void 		fill_nickname();
	void 		fill_phonenumber();
	void 		fill_secret();
};

#endif