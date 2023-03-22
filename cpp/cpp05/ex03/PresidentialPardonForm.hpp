/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:13:17 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:26:55 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H_
# define PRESIDENTIAL_PARDON_FORM_H_

# include "Form.hpp"

# include <string>

class PresidentialPardonForm : public Form {
public:
  PresidentialPardonForm(const std::string &target);
  ~PresidentialPardonForm(void);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

  void execute(Bureaucrat const &executor) const;
  const std::string &get_target(void) const;

  static const std::string kRequestString;

private:
  PresidentialPardonForm(void);
  PresidentialPardonForm(const PresidentialPardonForm &origin);

  static const int kRequiredSignGrade = 25;
  static const int kRequiredExecGrade = 5;
  static const std::string kFormName;

  const std::string target_;
};

#endif
