/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:05:25 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 17:35:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

const int max_zombies = 10;

int main() {
	Zombie *horde = zombieHorde(max_zombies, "zombie");

	for (int i = 0; i < max_zombies; i++)
		horde[i].announce();
	
	delete[] horde;
	return 0;
}