/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:43:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 22:45:28 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) : type_("") {
  std::cout << "[ Animal ] Default constructor is called" << std::endl;
}

Animal::Animal(const Animal &rhs) {
  std::cout << "[ Animal ] Copy constructor is called" << std::endl;
  *this = rhs;
}

Animal::~Animal(void) {
  std::cout << "[ Animal ] Destructor is called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
  type_ = rhs.type_;
  return *this;
}

const std::string &Animal::getType(void) const {
  return type_;
}
