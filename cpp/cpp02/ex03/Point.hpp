/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:52:06 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/30 23:15:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H_
# define POINT_H_

#include "Fixed.hpp"

class Point {
public:
  Point(void);
  Point(const float &x, const float &y);
  Point(const Point &point);
  Point &operator=(const Point &point);
  ~Point(void);

  Point operator-(const Point &point) const;

  const Fixed &get_x(void) const;
  const Fixed &get_y(void) const;
  void set_x(const Fixed &fixed);
  void set_y(const Fixed &fixed);


private:
  const Fixed x_;
  const Fixed y_;
};

#endif
