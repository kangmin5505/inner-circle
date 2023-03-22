/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:58:30 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 01:12:53 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

# include "utils.hpp"
# include "Contact.hpp"

class PhoneBook {
public:
	bool add(void);
	void search(void);
	PhoneBook(void);

private:
	const static int max_contacts_ = 8;
	Contact contacts_[max_contacts_];
	int cursor_;
	int left_space_;

	void print_all_contacts(void);
	void print_border(const char c);
	void print_contact(const Contact& contact, int idx);
	void print_header(void);
	int get_idx_prompt(void);
	bool is_valid_idx(const int idx);
	void print_detail_contact(const int idx);
	
};
#endif