/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:19:24 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/26 23:44:34 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H_
# define HARL_H_

#include <string>

class Harl {
public:
	void complain(std::string log);

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif