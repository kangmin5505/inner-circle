/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:13:17 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:26:48 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTO_MY_REQUEST_FORM_H_
# define ROBOTO_MY_REQUEST_FORM_H_

# include "Form.hpp"

# include <string>

class RobotomyRequestForm : public Form {
public:
  RobotomyRequestForm(const std::string &target);
  ~RobotomyRequestForm(void);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

  void execute(Bureaucrat const &executor) const;
  const std::string &get_target(void) const;

  static const std::string kRequestString;

private:
  RobotomyRequestForm(void);
  RobotomyRequestForm(const RobotomyRequestForm &origin);

  static const int kRequiredSignGrade = 72;
  static const int kRequiredExecGrade = 45;
  static const std::string kFormName;

  const std::string target_;
};

#endif
