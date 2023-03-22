/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:19:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/26 23:49:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H_
# define HARL_H_

#include <string>

class Harl {
public:
	void complain(std::string log);

private:
	static const size_t debug_   = 0;
	static const size_t info_    = 1;
	static const size_t warning_ = 2;
	static const size_t error_   = 3;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif