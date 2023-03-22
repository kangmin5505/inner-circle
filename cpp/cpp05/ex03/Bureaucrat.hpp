/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:40:05 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 01:00:15 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H_
# define BUREAUCRAT_H_

#include <string>
#include <iostream>
#include <exception>

const int kHighestGrade = 1;
const int kLowestGrade = 150;

class Form;

class Bureaucrat {
public:
  class GradeTooHighException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &origin);
  ~Bureaucrat(void);
  Bureaucrat &operator=(const Bureaucrat &rhs);

  const std::string &getName(void) const;
  const int &getGrade(void) const;
  void promotion(void);
  void relegation(void);
  void signForm(Form &form) const;
  void executeForm(Form const &form);
  
private:

  Bureaucrat(void);
  const std::string name_;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bure);

#endif
