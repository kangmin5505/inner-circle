/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:51:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 17:31:04 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void Zombie::set_name(const std::string& name) {
	name_ = name;
}

Zombie::Zombie() { }

Zombie::Zombie(const std::string &name) 
	: name_(name) { };

Zombie::~Zombie() {
	std::cout << name_ << ": destroyed..." << std::endl;
}

void Zombie::announce(void) {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}