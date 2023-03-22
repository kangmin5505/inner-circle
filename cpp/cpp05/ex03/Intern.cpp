/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:13:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:47:00 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const char *Intern::NoMatchingTypeException::what(void) const throw() {
  return "[ Intern ] No matching type.";
}

Intern::Intern(void) {}

Intern::~Intern(void) {}

Form *Intern::makeForm(const std::string &form_name, const std::string &target) {
  const std::string requests[Form::kFormTypeNum] = {
    ShrubberyCreationForm::kRequestString,
    RobotomyRequestForm::kRequestString,
    PresidentialPardonForm::kRequestString
  };
  try {
    for (int i = 0; i < Form::kFormTypeNum; i++) {
      if (form_name == requests[i]) {
        std::cout << "Intern creates " << requests[i] << std::endl;
        switch (i) {
          case 0 : return new ShrubberyCreationForm(target);
          case 1 : return new RobotomyRequestForm(target);
          case 2 : return new PresidentialPardonForm(target);
        }
      }
    }
    throw NoMatchingTypeException();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return NULL;
}
