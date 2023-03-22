/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:42:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 01:04:39 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
  std::cout << std::boolalpha;
  std::cout << "===== ShrubberyCreationForm test =====" << std::endl;
  ShrubberyCreationForm sh("shrub_normal_test");
  test_function(sh, "kang", 33);
  ShrubberyCreationForm sh2("shrub_catch_test1");
  test_function(sh2, "kang", 146);
  ShrubberyCreationForm sh3("shrub_catch_test2");
  test_function(sh3, "kang", 138);
  std::cout << std::endl;

  std::cout << "===== RobotomyRequestForm test =====" << std::endl;
  RobotomyRequestForm ro("roboto_normal_test");
  test_function(ro, "kang", 33);
  RobotomyRequestForm ro2("roboto_catch_test1");
  test_function(ro2, "kang", 73);
  RobotomyRequestForm ro3("roboto_catch_test2");
  test_function(ro3, "kang", 50);
  std::cout << std::endl;
  
  std::cout << "===== PresidentialPardonForm test =====" << std::endl;
  PresidentialPardonForm pr("prediential_normal_test");
  test_function(pr, "kang", 3);
  PresidentialPardonForm pr2("prediential_catch_test1");
  test_function(pr2, "kang", 26);
  PresidentialPardonForm pr3("prediential_catch_test2");
  test_function(pr3, "kang", 20);
  std::cout << std::endl;

}
