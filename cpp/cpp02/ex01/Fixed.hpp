/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 23:55:23 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/29 21:19:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H_
# define FIXED_H_

#include <iostream>
#include <ostream>

class Fixed {
public:
  Fixed(void);
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &fixed);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed(void);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;
  
  //friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private:
  static const int kFractionalBits = 8;
  int value_;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
