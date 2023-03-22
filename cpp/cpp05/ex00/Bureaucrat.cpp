/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:52:47 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/11 21:31:22 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
  : name_(name)
{
  if (grade < kHighestGrade)
    throw GradeTooHighException();
  if (grade > kLowestGrade)
    throw GradeTooLowException();
  grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin) { *this = origin; }

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  const_cast<std::string &>(name_) = rhs.name_;
  grade_ = rhs.grade_;
  return *this;
}

const std::string &Bureaucrat::getName(void) const { return name_; }

const int &Bureaucrat::getGrade(void) const { return grade_; }

void Bureaucrat::promotion(void) {
  if (grade_ - 1 < kHighestGrade)
    throw GradeTooHighException();
  --grade_;
}

void Bureaucrat::relegation(void) {
  if (grade_ + 1 > kLowestGrade)
    throw GradeTooLowException();
  ++grade_;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bure) {
  os << bure.getName() << ", bureaucrat grade "
      << bure.getGrade() << ".";
  return os;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "Grade is too low";
}
