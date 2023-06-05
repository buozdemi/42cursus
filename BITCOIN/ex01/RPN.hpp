/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:41 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/24 19:53:15 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

void			get_value_to_list(std::stack<int> &my_list, char *argv);
int				my_calculate(std::stack<int> &my_list_r);
void			symbol_func(int symbol, std::stack<int> &box);
bool			is_valid_ctrl(std::string str);
std::stack<int> reverse_stack(std::stack<int> &s);

#endif

