/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:49:34 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/09 23:31:27 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H_
# define MATERIASOURCE_H_

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# include <string>

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  ~MateriaSource();

  virtual void learnMateria(AMateria *m);
  virtual AMateria *createMateria(std::string const &type);

private:
  static const int kMaxCreateMateria = 4;
  static const int kMaxLearn = 4;

  AMateria *create_slot_[kMaxCreateMateria];
  AMateria *learn_slot_[kMaxLearn];
  int create_cnt_;
  int learn_cnt_;

  MateriaSource(const MateriaSource &origin);
  MateriaSource &operator=(const MateriaSource &rhs);
};

#endif
