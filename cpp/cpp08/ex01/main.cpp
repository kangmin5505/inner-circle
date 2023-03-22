/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:24:38 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/18 12:24:39 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <numeric>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "Span.hpp"

int main(void) {
    std::cout << "===== basic test =====" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "===== extra test =====" << std::endl;
    Span sp1 = Span(10000);
    sp1.addRange(0, 10000);
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "===== exception test =====" << std::endl;
    Span sp2(2);
    try {
        sp2.addNumber(1);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===== add number =====" << std::endl;
    try {
        sp2.addNumber(2);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        std::cout << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
