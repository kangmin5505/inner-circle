/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:51:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:44:51 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H_
# define FORM_H_

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class Form {
public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  class DoesNotSignedException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  class FileNotWorkingException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  Form(const Form &origin);
  Form(const std::string &name, int sign_grade, int exec_grade);
  virtual ~Form(void);
  Form &operator=(const Form &rhs);

  const std::string &get_name(void) const;
  const bool &get_is_signed(void) const;
  const int &get_signed_grade(void) const;
  const int &get_exec_grade(void) const;
  void beSigned(const Bureaucrat &b);

  virtual void execute(Bureaucrat const &executor) const = 0;

  static const int kFormTypeNum = 3;

protected:
  void executable(const Bureaucrat &b) const;

private:
  Form(void);

  const std::string name_;
  bool is_signed_;
  const int sign_grade_;
  const int exec_grade_;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
