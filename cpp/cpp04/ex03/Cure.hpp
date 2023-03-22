/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:10:26 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 22:50:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H_
# define CURE_H_

# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    ~Cure();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
private:
    Cure &operator=(const Cure &rhs);
    Cure(const Cure &origin);
};

#endif
