/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:37:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 18:43:44 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H_
# define HUMANA_H_

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string &name, const Weapon &type);
	void attack(void) const;
private:
	const std::string name_;
	const Weapon &weapon_;
};

#endif