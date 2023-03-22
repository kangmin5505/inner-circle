/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 22:57:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) {
  std::cout << "[ Cat ] Default constructor is called" << std::endl;
  type_ = "Cat";
}

Cat::Cat(const Cat &rhs) {
  std::cout << "[ Cat ] Copy constructor is called" << std::endl;
  *this = rhs;
}

Cat::~Cat(void) {
  std::cout << "[ Cat ] Destructor is called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
  type_ = rhs.type_;
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "[ Cat ] meow meow~~" << std::endl;
}
