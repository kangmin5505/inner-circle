/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:17:54 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/15 13:10:22 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

#include <iostream>
#include <exception>
#include <cctype>
#include <cmath>

Converter::Converter(const std::string &input)
  : input_(input), value_(0.0)
{
  try {
    const_cast<double &>(value_) = std::stod(input);
  } catch (std::exception &e) {
    throw e;
  }
}

Converter::~Converter(void) {}

const std::string &Converter::get_input(void) const { return input_; }

double Converter::get_value(void) const { return value_; }

void Converter::print(void) const {
  std::cout << std::showpoint;
  std::cout.setf(std::ios::fixed);
  std::cout.precision(1);

  print_to_char();
  print_to_int();
  print_to_float();
  print_to_double();

  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(6);
}

void Converter::print_to_char(void) const {
  double value = get_value();

  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << "impossible" << std::endl;
  else if (not std::isprint(value))
    std::cout << "Non displayable" << std::endl;
  else
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void Converter::print_to_int(void) const {
  double value = get_value();

  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void Converter::print_to_float(void) const {
  float value = static_cast<float>(get_value());

  if (std::isnan(value) || std::isinf(value)) {
    std::cout << std::showpos;
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << std::noshowpos;
  }
  else
    std::cout << "float: " << value << "f" << std::endl;
}

void Converter::print_to_double(void) const {
  double value = get_value();

  if (std::isnan(value) || std::isinf(value)) {
    std::cout << std::showpos;
    std::cout << "double: " << value << std::endl;
    std::cout << std::noshowpos;
  }
  else
    std::cout << "double: " << value << std::endl;
}
