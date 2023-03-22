/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:01:01 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) {
  std::cout << "[ WrongCat ] Default constructor is called" << std::endl;
  type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &rhs) {
  std::cout << "[ WrongCat ] Copy constructor is called" << std::endl;
  *this = rhs;
}

WrongCat::~WrongCat(void) {
  std::cout << "[ WrongCat ] Destructor is called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
  type_ = rhs.type_;
  return *this;
}

void WrongCat::makeSound(void) const {
  std::cout << "[ WrongCat ] meow meow~~" << std::endl;
}
