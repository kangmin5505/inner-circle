/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:52:18 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:32:06 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) {
  std::cout << "[ Dog ] Default constructor is called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain;
}

Dog::Dog(const Dog &rhs) {
  std::cout << "[ Dog ] Copy constructor is called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain;
  *brain_ = *(rhs.brain_);
}

Dog::~Dog(void) {
  std::cout << "[ Dog ] Destructor is called" << std::endl;
  delete brain_;
}

Dog &Dog::operator=(const Dog &rhs) {
  *(brain_) = *(rhs.brain_);
  return *this;
}

void Dog::makeSound(void) const {
  std::cout << "[ Dog ] bark bark!!" << std::endl;
}

void Dog::set_idea(int i, const std::string &idea) {
  (*brain_)[i] = idea;
}

const std::string &Dog::get_idea(int i) const {
  return (*brain_)[i];
}
