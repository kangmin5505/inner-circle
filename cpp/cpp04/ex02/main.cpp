/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:55:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:19:04 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

// #include <cstdlib>

int main() {
  Animal *arr[10];
  // Animal a; error : Abstract class can't create instance.

  std::cout << "===== Default constructor =====" << std::endl;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0)
      arr[i] = new Dog;
    else
      arr[i] = new Cat;
  }
  std::cout << std::endl;

  std::cout << "===== Destructor =====" << std::endl;
  for (int i = 0; i < 10; i++)
    delete arr[i];
  std::cout << std::endl;

  std::cout << "===== Deep copy =====" << std::endl;
  Dog dog;
  Cat cat;
  Dog dog2;
  Cat cat2(cat);

  dog2 = dog;

  dog2.set_idea(0, "another idea!!");
  cat2.set_idea(0, "another idea!!");

  std::cout << dog.get_idea(0) << std::endl;
  std::cout << cat.get_idea(0) << std::endl;
  std::cout << dog2.get_idea(0) << std::endl;
  std::cout << cat2.get_idea(0) << std::endl;
  std::cout << std::endl;

  // system("leaks main");
}
