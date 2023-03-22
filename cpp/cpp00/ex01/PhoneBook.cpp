/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:00:00 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/25 17:12:03 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook(void)
	: cursor_(0), left_space_(max_contacts_) { }

bool PhoneBook::add(void) {
	Contact& contact = contacts_[cursor_];
	std::string line;

	utils::getline_prompt(line, "1. first name : ");
	if (line.length() == 0 || not contact.set_first_name(line))
		return false;
	utils::getline_prompt(line, "2. last name : ");
	if (line.length() == 0 || not contact.set_last_name(line))
		return false;
	utils::getline_prompt(line, "3. nickname : ");
	if (line.length() == 0 || not contact.set_nickname(line))
		return false;
	utils::getline_prompt(line, "4. phone number : ");
	if (line.length() == 0 || not contact.set_phone_number(line))
		return false;
	utils::getline_prompt(line, "5. darkest secret : ");
	if (line.length() == 0 || not contact.set_darkest_secret(line))
		return false;
	
	cursor_ = (cursor_ == max_contacts_ - 1) ? 0 : cursor_ + 1;
	left_space_ = (left_space_ > 0) ? left_space_ - 1 : 0;
	return true;
}

int PhoneBook::get_idx_prompt(void) {
	std::string line;
	int	idx;

	std::cout << "- Select a idx : ";
	std::getline(std::cin, line);
	std::istringstream int_stream(line);
	int_stream >> idx;
	if (int_stream.fail())
		return -1;
	return idx;
}

bool PhoneBook::is_valid_idx(const int idx) {
	if (0 <= idx && idx < max_contacts_ - left_space_)
		return true;
	return false;
}

void PhoneBook::print_detail_contact(const int idx) {
	Contact& contact = contacts_[idx];

	std::cout << "First name     : " << contact.get_first_name() << std::endl;
	std::cout << "Last name      : " << contact.get_last_name() << std::endl;
	std::cout << "Nickname       : " << contact.get_nickname() << std::endl;
	std::cout << "Phone number   : " << contact.get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << contact.get_darkest_secret() << std::endl;
}

void PhoneBook::search(void) {
	int idx;

	if (left_space_ == max_contacts_) {
		std::cout << "* PhoneBook is empty" << std::endl;
		return;
	}
	print_all_contacts();
	idx = get_idx_prompt();
	if (is_valid_idx(idx))
		print_detail_contact(idx);
	else
		std::cout << "* Invalid idx" << std::endl;
}

void PhoneBook::print_all_contacts(void) {
	print_border('*');
	print_header();
	print_border('|');
	for (int i = 0; i < max_contacts_ - left_space_; i++)
		print_contact(contacts_[i], i);
	print_border('*');
}

void PhoneBook::print_contact(const Contact& contact, int idx) {
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << idx;
	std::cout << "|";
	utils::print_with_width(contact.get_first_name());
	std::cout << "|";
	utils::print_with_width(contact.get_last_name());
	std::cout << "|";
	utils::print_with_width(contact.get_nickname());
	std::cout << "|" << std::endl;
}

void PhoneBook::print_header(void) {
	std::cout << "|";
	utils::print_with_width("Index");
	std::cout << "|";
	utils::print_with_width("First name");
	std::cout << "|";
	utils::print_with_width("Last name");
	std::cout << "|";
	utils::print_with_width("Nickname");
	std::cout << "|" << std::endl;
}

void PhoneBook::print_border(const char c) {
	std::cout << c << std::setfill('-') << std::setw(44) << c << std::endl;
}
