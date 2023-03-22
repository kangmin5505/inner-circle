/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:38:29 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/24 17:46:17 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str memory address : " << &str << std::endl;
	std::cout << "stringPTR memory address : " << &stringPTR << std::endl;
	std::cout << "stringREF memory address : " << &stringREF << std::endl;

	std::cout << "str value : " << str << std::endl;
	std::cout << "stringPTR value : " << *stringPTR << std::endl;
	std::cout << "strringREF value : " << stringREF << std::endl;

	return 0;
}