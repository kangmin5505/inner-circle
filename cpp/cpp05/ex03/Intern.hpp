/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:06:29 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:36:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H_
# define INTERN_H_

# include <string>
# include <exception>

class Form;

class Intern {
public:
  class NoMatchingTypeException : public std::exception {
  public:
    const char *what(void) const throw();
  };

  Intern(void);
  ~Intern(void);

  Form *makeForm(const std::string &form_name, const std::string &target);
private:
  Intern(const Intern &origin);
  Intern &operator=(const Intern &rhs);
};

#endif
