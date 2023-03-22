/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:29:36 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/18 13:37:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <string>

void basic_test(void) {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
}

void list_test(void) {
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::list<int> s(mstack);
}

void iterator_test(void) {
    MutantStack<std::string> mstack;
    mstack.push("hello");
    mstack.push("I'm");
    mstack.push("kangkim");
    mstack.push("have a good day!");

    std::cout << "===== iterator =====" << std::endl;
    MutantStack<std::string>::iterator it = mstack.begin();
    MutantStack<std::string>::iterator end = mstack.end();
    for (; it != end; ++it)
        std::cout << *it << std::endl;
    std::cout << std::endl;

    std::cout << "===== const_iterator =====" << std::endl;
    MutantStack<std::string>::const_iterator cit = mstack.cbegin();
    MutantStack<std::string>::const_iterator cend = mstack.cend();
    for (; cit != cend; ++cit)
        std::cout << *cit << std::endl;
    std::cout << std::endl;

    std::cout << "===== const_reverse_iterator =====" << std::endl;
    MutantStack<std::string>::const_reverse_iterator cnit = mstack.rbegin();
    MutantStack<std::string>::const_reverse_iterator cnend = mstack.rend();
    for (; cnit != cnend; ++cnit)
        std::cout << *cnit << std::endl;
    std::cout << std::endl;

    std::cout << "===== reverse_iterator =====" << std::endl;
    MutantStack<std::string>::reverse_iterator rit = mstack.rbegin();
    MutantStack<std::string>::reverse_iterator rend = mstack.rend();
    for (; rit != rend; ++rit)
        std::cout << *rit << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << "===== basic test =====" << std::endl;
    basic_test();
    std::cout << std::endl;

    std::cout << "===== list test =====" << std::endl;
    list_test();

    std::cout << "===== iterator, const_iterator, const_reverse_iterator, "
                "reverse_iterator test =====" << std::endl;
    iterator_test();
    
}
