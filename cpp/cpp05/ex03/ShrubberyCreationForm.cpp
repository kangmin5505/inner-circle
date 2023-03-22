/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 23:04:30 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:25:02 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";
const std::string ShrubberyCreationForm::kRequestString = "shrubbery request";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
  : Form(kFormName, kRequiredSignGrade, kRequiredExecGrade)
{
  const_cast<std::string&>(target_) = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
  const_cast<std::string&>(target_) = rhs.get_target();
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  executable(executor);
  std::ofstream ostrm(get_target() + "_shrubery", std::ofstream::out | std::ofstream::trunc);
  if (!ostrm.good())
    throw FileNotWorkingException();
  ostrm <<      "    oxoxoo    ooxoo\n"
                "  ooxoxo oo  oxoxooo\n"
                " oooo xxoxoo ooo ooox\n"
                " oxo o oxoxo  xoxxoxo\n"
                "  oxo xooxoooo o ooo\n"
                "    ooo\\oo\\  /o/o\n"
                "        \\  \\/ /\n"
                "         |   /\n"
                "         |  |\n"
                "         | D|\n"
                "         |  |\n"
                "         |  |\n"
                "  ______/____\\____\n";
  std::cout << "Create Shrubbery file" << std::endl;
  ostrm.close();
}

const std::string &ShrubberyCreationForm::get_target(void) const { return target_; }
