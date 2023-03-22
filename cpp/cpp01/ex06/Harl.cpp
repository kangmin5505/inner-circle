/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:21:30 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 00:03:54 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string log) {
	const char *log_list[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t log_size = sizeof(log_list) / sizeof(*log_list);

	size_t i;
	for (i = 0; i < log_size; i++) {
		if (log_list[i] == log)
			break;
	}

	switch (i) {
	case debug_:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl;
	case info_:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl;
	case warning_:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl;
	case error_:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
	}
}

void Harl::debug(void) {
	std::cout << "Log level : Debug" << std::endl;
	std::cout << "A log level used for events considered to be using "
		"during software debugging when more granular information is needed."
		<< std::endl;
}

void Harl::info(void) {
	std::cout << "Log level : Info" << std::endl;
	std::cout << "An event happened, the event is purely informative "
		"and can be ignored during normal operations."
		<< std::endl;
}

void Harl::warning(void) {
	std::cout << "Log level : Warning" << std::endl;
	std::cout << "Unexpected behavior happened inside the application, "
		"but it is continuing its work and "
		"the key business features are operating as expected."
		<< std::endl;
}

void Harl::error(void) {
	std::cout << "Log level : Error" << std::endl;
	std::cout << "One or more functionalities are not working, "
		"preventing some functionalities from working correctly."
		<< std::endl;
}