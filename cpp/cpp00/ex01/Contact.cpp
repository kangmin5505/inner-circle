/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:51:14 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/23 22:01:24 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include "Contact.hpp"

// getter functions 
const std::string& Contact::get_first_name(void) const {
	return first_name_;
}

const std::string& Contact::get_last_name(void) const {
	return last_name_;
}

const std::string& Contact::get_nickname(void) const {
	return nickname_;
}

const std::string& Contact::get_phone_number(void) const {
	return phone_number_;
}

const std::string& Contact::get_darkest_secret(void) const {
	return darkest_secret_;
}

// setter functions 
bool Contact::set_first_name(const std::string& first_name) {
	bool is_valid = check_name(first_name);
	if (is_valid)
		first_name_ = first_name;
	return is_valid;
}

bool Contact::set_last_name(const std::string& last_name) {
	bool is_valid = check_name(last_name);
	if (is_valid)
		last_name_ = last_name;
	return is_valid;
}

bool Contact::set_nickname(const std::string& nickname) {
	nickname_ = nickname;
	return true;
}

bool Contact::set_phone_number(const std::string& phone_number) {
	bool is_valid = check_phone_number(phone_number);
	if (is_valid)
		phone_number_ = phone_number;
	return is_valid;
}

bool Contact::set_darkest_secret(const std::string& darkest_secret) {
	darkest_secret_ = darkest_secret;
	return true;
}

// checker
bool Contact::check_name(const std::string& name)
{
	for (int i = 0; name[i]; i++)
		if (not std::isalpha(name[i]))
			return false;
	return true;
}

bool Contact::check_phone_number(const std::string& phone_number)
{
	if (phone_number.length() != phone_number_length_)
		return false;
	for (int i = 0; i < phone_number_length_; i++) {
		if ((i == 3 || i == 8) && phone_number[i] != '-')
			return false;
		else if ((i != 3 && i != 8) && not std::isdigit(phone_number[i]))
			return false;
	}
	return true;
}