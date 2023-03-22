/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:13:09 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/13 13:27:39 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H_
# define CONVERTER_H_

# include <string>

class Converter {
public:
  Converter(const std::string &input);
  ~Converter(void);

  const std::string &get_input(void) const;
  double get_value(void) const;
  void print(void) const;

private:
  Converter(void);
  Converter(const Converter &origin);
  Converter &operator=(const Converter &rhs);

  void print_to_char(void) const;
  void print_to_int(void) const;
  void print_to_float(void) const;
  void print_to_double(void) const;

  const std::string input_;
  const double value_;
};

#endif
