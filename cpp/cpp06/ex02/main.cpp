/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:25:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 19:58:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

#include <cstdlib>
#include <ctime>

Base *generate(void) {
  int random_number = std::rand() % 3;

  switch (random_number) {
    case 0: return new A;
    case 1: return new B;
    case 2: return new C;
  }
  return NULL;
}

void identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  B *b = dynamic_cast<B *>(p);
  C *c = dynamic_cast<C *>(p);

  if (a) {
    std::cout << "A" << std::endl;
  } else if (b) {
    std::cout << "B" << std::endl;
  } else if (c) {
    std::cout << "C" << std::endl;
  }
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
    static_cast<void>(a);
  } catch (std::exception &e) {}

  try {
    B &b = dynamic_cast<B &>(p);
    std::cout << "B" << std::endl;
    static_cast<void>(b);
  } catch (std::exception &e) {}

  try {
    C &c = dynamic_cast<C &>(p);
    std::cout << "C" << std::endl;
    static_cast<void>(c);
  } catch (std::exception &e) {}
}

int main(void) {
  std::srand(std::time(nullptr));

  Base *base = generate();
  if (base) {
    identify(base);
    identify(*base);
  }
}
