/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:03:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 19:04:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, const Weapon &type)
	: name_(name), weapon_(type) { };

void HumanA::attack(void) const {
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}