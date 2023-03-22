/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:26:51 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/30 23:28:42 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_H_
# define BSP_H_

#include "Point.hpp"

namespace bsp {
bool bsp(Point const a, Point const b, Point const c, Point const point);
} // namespace bsp

#endif
