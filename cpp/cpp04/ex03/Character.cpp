/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:22:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:30:10 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>

Character::Character()
    : name_(""), inventory_cnt_(0), unequip_cnt_(0)
{
    for (int i = 0; i < kMaxSlot; i++)
        inventory_[i] = NULL;
    for (int i = 0; i < kMaxUnequip; i++)
        unequip_collector_[i] = NULL;
}

Character::Character(const Character &origin) {
    inventory_cnt_ = origin.inventory_cnt_;
    name_ = origin.name_;
    unequip_cnt_ = 0;

    for (int i = 0; i < kMaxSlot; i++) {
        if (origin.inventory_[i]) {
            inventory_[i] = origin.inventory_[i]->clone();
        }
        else
            inventory_[i] = NULL;
    }
    for (int i = 0; i < kMaxUnequip; i++)
        unequip_collector_[i] = NULL;
}

Character::Character(const std::string &name)
    : name_(name), inventory_cnt_(0), unequip_cnt_(0)
{
    for (int i = 0; i < kMaxSlot; i++)
        inventory_[i] = NULL;
    for (int i = 0; i < kMaxUnequip; i++)
        unequip_collector_[i] = NULL;
}

Character::~Character() {
    for (int i = 0; i < inventory_cnt_; i++)
        delete inventory_[i];
    for (int i = 0; i < unequip_cnt_; i++)
        delete unequip_collector_[i];
}

Character &Character::operator=(const Character &rhs) {
    if (this == &rhs)
        return *this;

    for (int i = 0; i < kMaxSlot; i++) {
        delete inventory_[i];
        inventory_[i] = NULL;
    }
    for (int i = 0; i < kMaxUnequip; i++) {
        delete unequip_collector_[i];
        unequip_collector_[i] = NULL;
    }

    inventory_cnt_ = rhs.inventory_cnt_;
    name_ = rhs.name_;
    unequip_cnt_ = 0;

    for (int i = 0; i < kMaxSlot; i++) {
        if (rhs.inventory_[i])
            inventory_[i] = rhs.inventory_[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const { return name_; }

void Character::equip(AMateria *m) {
    if (!m) {
        std::cout << "AMateria is NULL" << std::endl;
    }
    else if (inventory_cnt_ == kMaxSlot)
        std::cout << name_ << "'s slot is full" << std::endl;
    else {
        inventory_[inventory_cnt_] = m;
        inventory_cnt_++;
    }
}

void Character::unequip(int idx) {
    if (inventory_cnt_ == 0)
        std::cout << name_ << " doesn't have material." << std::endl;
    else if (idx >= kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else if (inventory_[idx] == NULL)
        std::cout << "Inventory of idx is empty" << std::endl;
    else if (unequip_cnt_ == kMaxUnequip)
        std::cout << "Can't unequip more " << kMaxUnequip << "." << std::endl;
    else {
        std::cout << name_ << " drops " << inventory_[idx]->getType() << " material." << std::endl;
        unequip_collector_[unequip_cnt_] = inventory_[idx];
        unequip_cnt_++;
        inventory_[idx] = NULL;
        inventory_cnt_--;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (inventory_cnt_ == 0 || not inventory_[idx])
        std::cout << name_ << " doesn't have material." << std::endl;
    else if (idx >= kMaxSlot || idx < 0)
        std::cout << "range out of idx" << std::endl;
    else
        inventory_[idx]->use(target);
}
