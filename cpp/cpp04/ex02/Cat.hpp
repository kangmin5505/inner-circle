/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:50:44 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 10:41:14 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H_
# define CAT_H_

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
public:
  Cat(void);
  Cat(const Cat &rhs);
  virtual ~Cat(void);
  Cat &operator=(const Cat &rhs);

  virtual void makeSound(void) const;

  void set_idea(int i, const std::string &idea);
  const std::string &get_idea(int i) const;

private:
  Brain *brain_;
};

#endif
