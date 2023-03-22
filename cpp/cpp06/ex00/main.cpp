/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:31:17 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 15:54:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <iostream>
#include <exception>
#include <iomanip>

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      Converter convertor(argv[1]);
      convertor.print();
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  else
    std::cerr << "usage : ./convert [literal] (only one)" << std::endl;
}
