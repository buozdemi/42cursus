/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:22:30 by buozdemi          #+#    #+#             */
/*   Updated: 2023/05/31 14:29:53 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	symbol_func(int symbol, std::stack<int> &box)
{
	int a, b;
	if (symbol == 43)
	{
		a = box.top();
		box.pop();
		b = box.top();
		box.pop();
		box.push(b + a);
	}
	if (symbol == 42)
	{
		a = box.top();
		box.pop();
		b = box.top();
		box.pop();
		box.push(b * a);
	}
	if (symbol == 47)
	{
		a = box.top();
		box.pop();
		b = box.top();
		box.pop();
		box.push(b / a);
	}
	if (symbol == 45)
	{
		a = box.top();
		box.pop();
		b = box.top();
		box.pop();
		box.push(b - a);
	}
}

std::stack<int> reverse_stack(std::stack<int> &s) 
{
    std::stack<int> reversed;
    while(!s.empty()) 
	{
        reversed.push(s.top());
        s.pop();
    }
    return reversed;
}

int	my_calculate(std::stack<int> &my_stack_r)
{
	std::stack<int> box;
	std::stack<int> my_stack = reverse_stack(my_stack_r);
	
	int symbol = 0;
	while (my_stack.size() != 0)
	{
		if (symbol != 0)
		{
			std::cout << "Error: Invalid RPN (Early symbol may have been placed.)" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (my_stack.top() != 42 && my_stack.top() != 43 && my_stack.top() != 45 && my_stack.top() != 47)
		{
			box.push(my_stack.top());
			my_stack.pop();
		}
		else
		{
			symbol = my_stack.top();
			my_stack.pop();
		}
		if (symbol != 0 && box.size() > 1)
		{
			symbol_func(symbol, box);
			symbol = 0;
		}
	}
	if (box.size() != 1)
	{
		std::cerr << "Error: Invalid RPN" << std::endl;
		exit(EXIT_FAILURE);
	}
	return box.top();
}

bool	is_valid_ctrl(std::string str)
{
	if ((isdigit(str[0]) || (str[0] == '*' || str[0] == '+' || str[0] == '-' || str[0] == '/')) && str[1] == '\0')
		return true;
	return false;
}

void	get_value_to_list(std::stack<int> &my_stack, char *argv)
{
	std::string str_arg(argv);
	int i = 0;
	while (str_arg[i] != '\0')
	{
		if (str_arg[0] == ' ')
		{
			std::cerr << "Error: You entered wrong value as argument." << std::endl;
			exit(EXIT_FAILURE);
		}
		while (str_arg[i] == ' ')
			i++;
		int m = i;
		while (str_arg[i] != '\0' && str_arg[i] != ' ') 
			i++;
		std::string signum = str_arg.substr(m, i - m);
		if (is_valid_ctrl(signum))
		{
			if (isdigit(signum[0]))
				my_stack.push(std::atoi(signum.c_str()));
			else
				my_stack.push(signum[0]);
		}
		else
		{
			std::cerr << "Error: You entered wrong value as argument." << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}
