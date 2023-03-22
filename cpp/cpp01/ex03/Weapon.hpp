/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:48 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 18:52:28 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H_
# define WEAPON_H_

#include <string>

class Weapon {
public:
	Weapon(const std::string &type);
	const std::string &getType(void) const;
	void setType(const std::string type);

private:
	std::string type_;
};
#endif