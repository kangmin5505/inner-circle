/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:16:37 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) {
  std::cout << "[ Cat ] Default constructor is called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain;
}

Cat::Cat(const Cat &rhs) {
  std::cout << "[ Cat ] Copy constructor is called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain;
  *(brain_) = *(rhs.brain_);
  // brain_ = rhs.brain_; // error : shallow copy
}

Cat::~Cat(void) {
  std::cout << "[ Cat ] Destructor is called" << std::endl;
  delete brain_;
}

Cat &Cat::operator=(const Cat &rhs) {
  *(brain_) = *(rhs.brain_);
  return *this;
}

void Cat::makeSound(void) const {
  std::cout << "[ Cat ] meow meow~~" << std::endl;
}

void Cat::set_idea(int i, const std::string &idea) {
  (*brain_)[i] = idea;
}

const std::string &Cat::get_idea(int i) const {
  return (*brain_)[i];
}
