/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:26:41 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/08 23:04:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H_
# define AMATERIA_H_

# include <string>

class ICharacter;

class AMateria {
public:
    AMateria();
    virtual ~AMateria();

    AMateria(std::string const &type);
    std::string const &getType() const;
    void setType(std::string const &type);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target) = 0;

protected:
    std::string type_;

    AMateria(const AMateria &origin);
    AMateria &operator=(const AMateria &rhs);
};

#endif
