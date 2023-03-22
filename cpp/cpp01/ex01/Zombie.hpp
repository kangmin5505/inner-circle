/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:48:23 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 17:04:23 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H_
# define ZOMBIE_H_

#include <string>

class Zombie {
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();
	void announce(void);
	void set_name(const std::string &name);
private:
	std::string name_;
};

Zombie* zombieHorde(int n, const std::string &name);

#endif