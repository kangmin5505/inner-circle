/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:55:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 10:37:34 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void) {
  std::cout << "===== Default Constructor =====" << std::endl;

  const Animal* meta = new Animal();
  const Animal* cat = new Cat();
  const Animal* dog = new Dog();
  std::cout << std::endl;

  
  std::cout << "===== getType() =====" << std::endl;

  std::cout << cat->getType() << " " << std::endl;
  std::cout << dog->getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << "===== makeSound() =====" << std::endl;

  meta->makeSound();
  cat->makeSound();
  dog->makeSound();
  std::cout << std::endl;

  std::cout << "===== Destructor =====" << std::endl;

  delete meta;
  delete cat;
  delete dog;
  std::cout << std::endl;

  std::cout << "===== Start wrong cases =====" << std::endl;
  std::cout << "===== Default Constructor =====" << std::endl;

  const WrongAnimal* wrong_meta = new WrongAnimal();
  const WrongAnimal* wrong_cat = new WrongCat();
  std::cout << std::endl;

  
  std::cout << "===== getType() =====" << std::endl;

  std::cout << wrong_cat->getType() << " " << std::endl;
  std::cout << std::endl;

  std::cout << "===== makeSound() =====" << std::endl;

  wrong_meta->makeSound();
  wrong_cat->makeSound();
  std::cout << std::endl;

  std::cout << "===== Destructor =====" << std::endl;

  delete wrong_meta;
  delete wrong_cat;
  std::cout << std::endl;
}
