/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:42:20 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/11 21:46:03 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test_function(const std::string name, int grade, void (Bureaucrat::*f)(void)) {
  std::cout << "===== " << name << " =====" << std::endl;
  try {
    Bureaucrat b(name, grade);
    (b.*f)();
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << std::endl;
}

int main() {
  test_function("promotion test", 3, &Bureaucrat::promotion);
  test_function("relegation test", 3, &Bureaucrat::relegation);
  test_function("too high init grade", 0, &Bureaucrat::promotion);
  test_function("too low init grade", 151, &Bureaucrat::relegation);
  test_function("promotion too high", 1, &Bureaucrat::promotion);
  test_function("relegation too low", 150, &Bureaucrat::relegation);
}
