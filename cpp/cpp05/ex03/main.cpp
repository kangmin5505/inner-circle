/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:42:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 10:54:59 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iomanip>

void test_function(Form &f, const std::string b_name, int b_grade)
{
  std::cout << "===== " << b_name << " =====" << std::endl;
  try {
    Bureaucrat b(b_name, b_grade);
    std::cout << b << std::endl;
    std::cout << std::endl;

    b.signForm(f);
    std::cout << std::endl;

    std::cout << f << std::endl;
    b.executeForm(f);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  Intern intern;
  Form *form;

  std::cout << std::boolalpha;

  std::cout << "========== shrubbery test ==========" << std::endl;
  form = intern.makeForm(ShrubberyCreationForm::kRequestString, "shrubbery test");
  if (form) {
    test_function(*form, "kangkim", 10);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "========== robotomy test ==========" << std::endl;
  form = intern.makeForm(RobotomyRequestForm::kRequestString, "roboto test");
  if (form) {
    test_function(*form, "kangkim", 10);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "========== presidential pardon test ==========" << std::endl;
  form = intern.makeForm(PresidentialPardonForm::kRequestString, "presidential pardon test");
  if (form) {
    test_function(*form, "kangkim", 10);
    delete form;
  }
  std::cout << std::endl;

  std::cout << "========== wrong test ==========" << std::endl;
  form = intern.makeForm("wrong requset", "wrong request");
  if (form) {
    test_function(*form, "kangkim", 10);
    delete form;
  }

}
