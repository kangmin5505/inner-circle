/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:17:45 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 01:07:09 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void utils::print_banner(void) {
	std::cout << utils::banner << std::endl;
}

void utils::getline_prompt(std::string& line, const std::string& prompt) {
	std::cout << prompt;
	std::getline(std::cin, line);
	if (std::cin.eof())
		std::cout << std::endl;
}

void utils::print_cmd_guideline(void) {
	std::cout << "Try ADD or SEARCH or EXIT" << std::endl;
}

void utils::print_with_width(const std::string& str) {
	std::cout << std::setfill(' ');
	if (str.length() > column_width_)
		std::cout << str.substr(0, column_width_ - 1) << ".";
	else
		std::cout << std::setw(column_width_) << str;
}