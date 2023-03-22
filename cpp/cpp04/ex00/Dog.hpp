/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:50:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 10:39:52 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
# define DOG_H_

# include "Animal.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(const Dog &rhs);
  virtual ~Dog(void);
  Dog &operator=(const Dog &rhs);

  virtual void makeSound(void) const;

};

#endif
