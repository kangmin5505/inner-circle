/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:41:22 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 23:02:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H_
# define WRONGANIMAL_H_

# include <string>

class WrongAnimal {
public:
  WrongAnimal(void);
  WrongAnimal(const WrongAnimal &rhs);
  ~WrongAnimal(void);
  WrongAnimal &operator=(const WrongAnimal &rhs);

  void makeSound(void) const;

  const std::string &getType(void) const;

protected:
  std::string type_;
};

#endif
