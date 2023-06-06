/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:52:35 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/16 14:53:57 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTREAM_HPP
# define FSTREAM_HPP
#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string cont, std::string tofind, std::string toreplace);
int error(std::string fileName, std::string search, std::string replace);

#endif