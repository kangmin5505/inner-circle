/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:59:37 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 17:31:32 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, const std::string &name) {
	Zombie *horde = new Zombie[n];

	for (int i = 0; i < n; i++)
		horde[i].set_name(name);
	return horde;
}