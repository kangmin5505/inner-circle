/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:18:03 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/17 23:46:30 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <iostream>

#include "easyfind.hpp"

int main(void) {
    std::vector<int> v_container;
    std::list<int> l_container;
    std::deque<int> d_container;

    for (int i = 0; i < 10; ++i) {
        v_container.push_back(i);
        l_container.push_back(i);
        d_container.push_back(i);
    }

    std::cout << "===== test with vector =====" << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::vector<int>::iterator v_it = easyfind(v_container, i);
        if (v_it == v_container.end())
            std::cerr << i << " is not founded" << std::endl;
        else
            std::cout << i << " is founded!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== test with list =====" << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::list<int>::iterator l_it = easyfind(l_container, i);
        if (l_it == l_container.end())
            std::cerr << i << " is not founded" << std::endl;
        else
            std::cout << i << " is founded!" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "===== test with deque =====" << std::endl;
    for (int i = 0; i < 15; ++i) {
        std::deque<int>::iterator d_it = easyfind(d_container, i);
        if (d_it == d_container.end())
            std::cerr << i << " is not founded" << std::endl;
        else
            std::cout << i << " is founded!" << std::endl;
    }
    std::cout << std::endl;
}
