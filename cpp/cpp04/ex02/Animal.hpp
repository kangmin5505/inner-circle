/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:41:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 10:40:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H_
# define ANIMAL_H_

# include <string>

class Animal {
public:
  Animal(void);
  Animal(const Animal &rhs);
  virtual ~Animal(void);
  Animal &operator=(const Animal &rhs);

  virtual void makeSound(void) const = 0;

  const std::string &getType(void) const;

protected:
  std::string type_;

};

#endif
