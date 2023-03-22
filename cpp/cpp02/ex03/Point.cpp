/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:13:49 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/30 23:32:43 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {}

Point::Point(const float &x, const float &y) : x_(x), y_(y) {}

Point::Point(const Point &point) { *this = point; }

Point &Point::operator=(const Point &point) {
  const_cast<Fixed &>(this->x_) = point.get_x();
  const_cast<Fixed &>(this->y_) = point.get_y();
  return *this;
}

Point Point::operator-(Point const &point) const {
  Point p;

  p.set_x(this->x_ - point.x_);
  p.set_y(this->y_ - point.y_);
  return p;
}

Point::~Point(void) {}

const Fixed &Point::get_x(void) const { return x_; }

const Fixed &Point::get_y(void) const { return y_; }

void Point::set_x(const Fixed &fixed) {
  const_cast<Fixed &>(this->x_) = fixed.getRawBits();
}

void Point::set_y(const Fixed &fixed) {
  const_cast<Fixed &>(this->y_) = fixed.getRawBits();
}
