/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:17:43 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:24:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>

const std::string RobotomyRequestForm::kFormName = "RobotomyRequestForm";
const std::string RobotomyRequestForm::kRequestString = "robotomy request";

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
  : Form(kFormName, kRequiredSignGrade, kRequiredExecGrade)
{
  const_cast<std::string&>(target_) = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
  const_cast<std::string&>(target_) = rhs.get_target();
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  executable(executor);

  std::cout << "drrrrrrrr..........drrrrrrrrrrr..." << std::endl;

  int t = std::time(nullptr);
  std::srand(t);
  if (std::rand() % 2 == 0)
    std::cout << get_target() << " has been robotomized successfully." << std::endl;
  else
    std::cout << get_target() << " fail to be robotomized." << std::endl;
}

const std::string &RobotomyRequestForm::get_target(void) const { return target_; }
