/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:54:48 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 19:03:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name_(name), weapon_(nullptr) { };

void HumanB::attack(void) const {
	if (weapon_)
		std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
	else
		std::cout << name_ << " attacks with his fist"<< std::endl;
}

void HumanB::setWeapon(const Weapon &weapon) {
	weapon_ = &weapon;
}