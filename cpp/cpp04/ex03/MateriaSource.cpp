/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:51:38 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/09 23:39:22 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <string>
#include <iostream>

MateriaSource::MateriaSource() 
  : create_cnt_(0), learn_cnt_(0)
{
  for (int i = 0; i < kMaxCreateMateria; i++)
    create_slot_[i] = NULL;
  for (int i = 0; i < kMaxLearn; i++)
    learn_slot_[i] = NULL;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < create_cnt_; i++)
    delete create_slot_[i];
  for (int i = 0; i < learn_cnt_; i++)
    delete learn_slot_[i];
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m && learn_cnt_ < kMaxLearn) {
    learn_slot_[learn_cnt_] = m;
    learn_cnt_++;
  }
  else if (learn_cnt_ == kMaxLearn) {
    std::cout << "learnMateria is full" << std::endl;
    delete m;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  if (create_cnt_ == kMaxCreateMateria) {
    std::cout << "Can't create more " << kMaxCreateMateria << "." << std::endl;
    return NULL;
  }

  for (int i = 0; i < learn_cnt_; i++) {
    if (learn_slot_[i]->getType() == type) {
      create_slot_[create_cnt_] = learn_slot_[i]->clone();
      return create_slot_[create_cnt_++]->clone();
    }
  }

  std::cout << "Don't have " << type << " type." << std::endl;
  return NULL;
}
