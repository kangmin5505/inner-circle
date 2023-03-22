/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:28 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 18:52:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
	: type_(type) { };

const std::string &Weapon::getType(void) const {
	return type_;
}

void Weapon::setType(const std::string type) {
	type_ = type;
}