/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:52:25 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/23 00:17:51 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

void	print_upper_all(const char* & str)
{
	for (int i = 0; str[i]; i++)
		cout << static_cast<char>(std::toupper(str[i]));
}

int main(int argc, const char **argv)
{
	if (argc < 2)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	else {
		for (int i = 1; i < argc; i++)
			print_upper_all(argv[i]);
		cout << endl;
	}
}