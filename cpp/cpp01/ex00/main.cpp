/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:47:54 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 16:46:49 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	{
		Zombie stack("stack");
		stack.announce();
	}
	Zombie *pheap = nullptr;
	{
		Zombie *heap = newZombie("heap");
		heap->announce();
		pheap = heap;
	}
	// stack.announce(); error
	pheap->announce();
	delete pheap;
	pheap = nullptr;

	randomChump("random");
	return 0;
}