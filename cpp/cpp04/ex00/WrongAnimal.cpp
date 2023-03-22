/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:43:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:00:55 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) : type_("") {
  std::cout << "[ WrongAnimal ] Default constructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs) {
  std::cout << "[ WrongAnimal ] Copy constructor is called" << std::endl;
  *this = rhs;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "[ WrongAnimal ] Destructor is called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
  type_ = rhs.type_;
  return *this;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "[ WrongAnimal ] ???" << std::endl;
}

const std::string &WrongAnimal::getType(void) const {
  return type_;
}
