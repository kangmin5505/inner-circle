/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:07:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/17 23:38:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H_
# define EASY_FIND_H_

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T &int_container, int value) {
    return std::find(int_container.begin(), int_container.end(), value);
}


#endif
