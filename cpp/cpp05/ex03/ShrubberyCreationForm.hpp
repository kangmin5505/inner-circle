/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:11:58 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:27:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H_ 
# define SHRUBBERY_CREATION_FORM_H_ 

# include "Form.hpp"

# include <string>

class ShrubberyCreationForm : public Form {
public:
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm(void);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

  void execute(Bureaucrat const &executor) const;
  const std::string &get_target(void) const;

  static const std::string kRequestString;

private:
  ShrubberyCreationForm(void);
  ShrubberyCreationForm(const ShrubberyCreationForm &origin);

  static const int kRequiredSignGrade = 145;
  static const int kRequiredExecGrade = 137;
  static const std::string kFormName;

  const std::string target_;
};

#endif
