/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:37:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 18:55:57 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H_
# define HUMANB_H_

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(const std::string &name);
	void attack(void) const;
	void setWeapon(const Weapon &weapon);

private:
	const std::string name_;
	const Weapon *weapon_;
};

#endif