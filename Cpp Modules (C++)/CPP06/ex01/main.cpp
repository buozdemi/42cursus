/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:32:10 by buozdemi          #+#    #+#             */
/*   Updated: 2023/04/24 11:31:30 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *ptr = new Data;
	ptr->data = "Leon";
	ptr->number = 618;

	uintptr_t ret_int = Serializer::serialize(ptr);
	Data *poi = Serializer::deserialize(ret_int);
	std::cout << "Poi's data : " << poi->data << std::endl;
	std::cout << "Ptr's data : " << ptr->data << std::endl;
	std::cout << "Poi's number : " <<  poi->number << std::endl;
	std::cout << "Ptr's number : " <<  ptr->number << std::endl;

	if (poi == ptr) 
		std::cout << "deserialize() returns the original pointer" << std::endl;

	std::cout << "poi adress: " << poi << std::endl;
	std::cout << "ptr adress: " << ptr << std::endl;

	delete ptr;
	return 0;
}
