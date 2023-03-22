/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:17:43 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:23:40 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::kFormName = "PresidentialPardonForm";
const std::string PresidentialPardonForm::kRequestString = "presidential pardon request";

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
  : Form(kFormName, kRequiredSignGrade, kRequiredExecGrade)
{
  const_cast<std::string&>(target_) = target;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
  const_cast<std::string&>(target_) = rhs.get_target();
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  executable(executor);
  std::cout << get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string &PresidentialPardonForm::get_target(void) const { return target_; }
