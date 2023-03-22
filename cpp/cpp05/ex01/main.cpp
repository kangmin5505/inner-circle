/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:42:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/12 00:40:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iomanip>

void test_function(const std::string b_name, int b_grade,
                  const std::string &f_name, int f_sign_grade,
                  int f_exec_grade)
{
  std::cout << "===== " << b_name << " =====" << std::endl;
  try {
    Bureaucrat b(b_name, b_grade);
    Form f(f_name, f_sign_grade, f_exec_grade);
    std::cout << b << std::endl;
    std::cout << f << std::endl;
    // b.promotion();
    b.signForm(f);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  std::cout << std::boolalpha;
  test_function("kangkim", 10, "test_form", 10, 10);
  test_function("kangkim", 11, "test_form", 10, 10);
  test_function("kangkim", 10, "test_form", 0, 10);
  test_function("kangkim", 11, "test_form", 10, 0);
  test_function("kangkim", 10, "test_form", 155, 10);
  test_function("kangkim", 11, "test_form", 10, 155);
}
