/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 22:58:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
  std::cout << "[ Dog ] Default constructor is called" << std::endl;
  type_ = "Dog";
}

Dog::Dog(const Dog &rhs) {
  std::cout << "[ Dog ] Copy constructor is called" << std::endl;
  *this = rhs;
}

Dog::~Dog(void) {
  std::cout << "[ Dog ] Destructor is called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
  type_ = rhs.type_;
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "[ Dog ] bark bark!!" << std::endl;
}
