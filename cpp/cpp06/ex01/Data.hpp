/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:32:51 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 18:16:33 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H_
# define DATA_H_

# include <string>
# include <iostream>

struct Data {
  Data(const std::string &n, const std::string &p, int a);
  
  std::string name;
  std::string phone_number;
  int age;
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif
