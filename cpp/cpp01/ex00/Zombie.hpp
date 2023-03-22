/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:48:23 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 16:03:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_
# define ZOMBIE_H_

#include <string>

class Zombie {
public:
	Zombie(const std::string& name);
	~Zombie(void);
	void announce(void);
private:
	std::string name_;
};

Zombie* newZombie(const std::string &name);
void randomChump(const std::string &name);

#endif