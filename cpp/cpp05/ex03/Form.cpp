/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:08:05 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/12 23:37:06 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what(void) const throw() {
  return "[ Form ] Grade is too high.";
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return "[ Form ] Grade is too low.";
}

const char *Form::DoesNotSignedException::what(void) const throw() {
  return "[ Form ] Does not signed.";
}

const char *Form::FileNotWorkingException::what(void) const throw() {
  return "[ Form ] Does not working file.";
}

Form::Form(const Form &origin)
  : name_(origin.get_name()), is_signed_(false), sign_grade_(origin.get_signed_grade()),
    exec_grade_(origin.get_exec_grade()) {}

Form::Form(const std::string &name, int sign_grade, int exec_grade)
  : name_(name), is_signed_(false), sign_grade_(sign_grade),
    exec_grade_(exec_grade)
{
  if (sign_grade_ < kHighestGrade || exec_grade_ < kHighestGrade)
    throw GradeTooHighException();
  if (sign_grade_ > kLowestGrade || exec_grade_ > kLowestGrade)
    throw GradeTooLowException();
}

Form::~Form(void) {}

Form &Form::operator=(const Form &rhs) {
  const_cast<std::string&>(name_) = rhs.get_name();
  is_signed_ = rhs.get_is_signed();
  const_cast<int&>(sign_grade_) = rhs.get_signed_grade();
  const_cast<int&>(exec_grade_) = rhs.get_exec_grade();
  return *this;
}

const std::string &Form::get_name(void) const { return name_; }

const bool &Form::get_is_signed(void) const { return is_signed_; }

const int &Form::get_signed_grade(void) const { return sign_grade_; }

const int &Form::get_exec_grade(void) const { return exec_grade_; }

void Form::beSigned(const Bureaucrat &b) {
  if (b.getGrade() > get_signed_grade())
    throw Bureaucrat::GradeTooLowException();
  is_signed_ = true;
}

Form::Form(void) : sign_grade_(0), exec_grade_(0) {}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "name : " << form.get_name() << std::endl;
  os << "is signed : " << form.get_is_signed() << std::endl;
  os << "sign grade : " << form.get_signed_grade() << std::endl;
  os << "exec grade : " << form.get_exec_grade() << std::endl;
  return os;
}

void Form::executable(const Bureaucrat &b) const {
  if (!get_is_signed())
    throw DoesNotSignedException();
  if (b.getGrade() > get_exec_grade())
    throw GradeTooLowException();
}
