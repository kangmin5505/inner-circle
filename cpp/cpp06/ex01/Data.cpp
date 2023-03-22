/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:05:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 18:17:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


Data::Data(const std::string &n, const std::string &p, int a)
  : name(n), phone_number(p), age(a) {}

std::ostream &operator<<(std::ostream &os, const Data &data) {
  os << "name : " << data.name << "\n"
      << "phone number : " << data.phone_number << "\n"
      << "age : " << data.age;
  return os;
}
