/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:26:41 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:23:04 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
  std::cout << "[ Brain ] Default Constructor is called" << std::endl;
  for (int i = 0; i < kMaxIdeas; i++)
    set_idea(i, "default idea");
}

Brain::Brain(const Brain &origin) {
  std::cout << "[ Brain ] Copy Constructor is called" << std::endl;
  for (int i = 0; i < kMaxIdeas; i++)
    set_idea(i, origin.get_idea(i));
}

Brain::~Brain() {
  std::cout << "[ Brain ] Destructor is called" << std::endl;
}

Brain &Brain::operator=(const Brain &rhs) {
  for (int i = 0; i < kMaxIdeas; i++)
    set_idea(i, rhs.get_idea(i));
  return *this;
}

std::string &Brain::operator[](int i) {
  return ideas_[i];
}

void Brain::set_idea(int i, const std::string &idea) {
  ideas_[i] = idea;
}

const std::string &Brain::get_idea(int i) const {
  return ideas_[i];
}
