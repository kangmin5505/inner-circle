/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:36:13 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 22:42:39 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H_
# define ICE_H_

# include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    ~Ice();

    virtual AMateria *clone() const;
    virtual void use(ICharacter &target);
private:
    Ice(const Ice &origin);
    Ice &operator=(const Ice &rhs);

};

#endif
