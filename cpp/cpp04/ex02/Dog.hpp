/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:50:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 10:41:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H_
# define DOG_H_

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(const Dog &rhs);
  virtual ~Dog(void);
  Dog &operator=(const Dog &rhs);

  virtual void makeSound(void) const;

  void set_idea(int i, const std::string &idea);
  const std::string &get_idea(int i) const;

private:
  Brain *brain_;
};

#endif
