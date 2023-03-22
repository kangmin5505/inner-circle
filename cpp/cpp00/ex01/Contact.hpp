/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:33:27 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 01:12:47 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
# define CONTACT_H_

#include <string>

class Contact {
public:
	// getter functions
	const std::string& get_first_name(void) const;
	const std::string& get_last_name(void) const;
	const std::string& get_nickname(void) const;
	const std::string& get_phone_number(void) const;
	const std::string& get_darkest_secret(void) const;
	// setter functions
	bool set_first_name(const std::string& first_name_);
	bool set_last_name(const std::string& last_name_);
	bool set_nickname(const std::string& nickname_);
	bool set_phone_number(const std::string& phone_number_);
	bool set_darkest_secret(const std::string& darkest_secret_);

private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

	const static int phone_number_length_ = 13;

	bool check_phone_number(const std::string& phone_number);
	bool check_name(const std::string& name);
};

#endif