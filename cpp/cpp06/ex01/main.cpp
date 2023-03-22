/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:03:53 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 18:19:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr) {
  uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
  return p;
}

Data *deserialize(uintptr_t raw) {
  Data *d = reinterpret_cast<Data*>(raw);
  return d;
}

int main() {
  Data *data[3] = { new Data("kang", "010-1231-1231", 28),
                    new Data("min", "010-3333-1123", 24),
                    new Data("kangkim", "010-2424-3131", 23)
                  };

  uintptr_t raw;
  Data *ret_data;
  for (int i = 0; i < 3; ++i) {
    std::cout << "===== origin data =====" << std::endl;
    std::cout << *data[i] << std::endl;

    raw = serialize(data[i]);
    ret_data = deserialize(raw);
    std::cout << "===== deserialized data =====" << std::endl;
    std::cout << *ret_data << std::endl;
    std::cout << std::endl;
  }

  for (int i = 0; i < 3; i++)
    delete data[i];

}
