/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:59:38 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 00:19:03 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string line;
	PhoneBook phonebook;

	utils::print_banner();
	while (true)
	{
		utils::getline_prompt(line, "> ");
		if (std::cin.eof() || line == "EXIT")
			break;
		else if (line == "ADD") {
			if (phonebook.add())
				std::cout << "* update success" << std::endl;
			else
				std::cout << "* update fail" << std::endl;
		}
		else if (line == "SEARCH")
			phonebook.search();
	}
	return 0;
}