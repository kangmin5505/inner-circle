/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:06:50 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/04 16:39:28 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H_
# define FRAGTRAP_H_

# include "ClapTrap.hpp"

# include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap(void);
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &fragtrap);
  ~FragTrap(void);
  FragTrap &operator=(const FragTrap &fragtrap);

  void attack(const std::string &target);

  void highFivesGuys(void);

private:
  static const std::string kRobotType;
  static const unsigned int kHitPoints = 100;
  static const unsigned int kEnergyPoints = 100;
  static const unsigned int kAttackDamage = 30;
};

#endif
