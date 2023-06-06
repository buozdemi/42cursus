/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buozdemi <buozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:51:54 by buozdemi          #+#    #+#             */
/*   Updated: 2023/03/22 14:47:43 by buozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap: public ClapTrap
{   
    public:
        FragTrap();
        FragTrap(const std::string& name);
        ~FragTrap();
        void highFivesGuys(void);
};
