/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:11:32 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 01:12:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H_
# define UTILS_H_

#include <string>
#include <iostream>
#include <iomanip>

namespace utils {
	static const char *const banner =
		"*---------------------------------------*\n"
		"| Hello!                                |\n"
		"| This is PhoneBook program             |\n"
		"| Commands:                             |\n"
		"| - ADD    : save a new contact         |\n"
		"| - SEARCH : display a specific contact |\n"
		"| - EXIT   : exit a program             |\n"
		"*---------------------------------------*\n";
	const static int column_width_ = 10;

	void print_banner(void);
	void getline_prompt(std::string& line, const std::string& prompt);
	void print_cmd_guideline(void);
	void print_with_width(const std::string& str);

}	// namespace utils

#endif