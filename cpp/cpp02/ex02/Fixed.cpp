/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:01:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/30 00:15:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void) : value_(0) { }

Fixed::Fixed(const int value)
  : value_(value * (1 << kFractionalBits)) { }

Fixed::Fixed(const float value)
  : value_(std::roundf(value * (1 << kFractionalBits))) { }

Fixed::Fixed(const Fixed &fixed) {
  *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
  value_ = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed(void) { }

bool Fixed::operator==(const Fixed &fixed) const {
  return value_ == fixed.getRawBits();
}

bool Fixed::operator>(const Fixed &fixed) const {
  return value_ > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
  return value_ < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return value_ >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return value_ <= fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return value_ != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
  Fixed f;

  f.setRawBits(value_ + fixed.value_);
  return f;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
  Fixed f;

  f.setRawBits(value_ - fixed.value_);
  return f;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
  return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
  return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
  ++value_;
  return *this;
}

Fixed &Fixed::operator--(void) {
  --value_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);

  ++value_;
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);

  --value_;
  return temp;
}

const Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return f1 > f2 ? f1 : f2;
}

const Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return f1 < f2 ? f1 : f2;
}

int Fixed::getRawBits (void) const {
  return value_;
}

void Fixed::setRawBits (int const raw) {
  value_ = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(value_) / (1 << kFractionalBits);
}

int Fixed::toInt(void) const {
  return value_ / (1 << kFractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return os;
}
