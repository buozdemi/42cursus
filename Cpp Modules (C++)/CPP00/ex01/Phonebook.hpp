/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:37:35 by buozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 11:22:54 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_HPP
# define PH_HPP
# include "Contact.hpp" 

class PhoneBook {
	int index_fill;
	int index_write;
	int full_people;
	Contact contacts[8];
public:
	PhoneBook() : index_fill(0), index_write(0), full_people(0) {}
	void 	index_fill_plus();
	void 	index_write_plus();
	void 	index_write_new_value(int i);
	int 	get_index_fill();
	int 	get_index_write();
	Contact *getContact_len();
	Contact getContact();
	Contact getContact_num(int i);
	int 	get_full_people();
	void 	my_search();
	void 	choose_name();
};

void	front_data(int data_num);

#endif
