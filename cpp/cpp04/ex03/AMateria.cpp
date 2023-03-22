/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:49:09 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 23:02:37 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <string>

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const &type) {
    setType(type);
}

std::string const &AMateria::getType() const { return type_; }

void AMateria::setType(std::string const &type) { type_ = type; }
