/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:24:42 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/18 12:01:48 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <numeric>

Span::Span(const std::size_t &size)
:   size_(size)
{
    elems_.reserve(size);
}

Span::Span(const Span &origin)
:   size_(origin.size_)
{
    elems_.reserve(origin.elems_.capacity());
    std::copy(origin.elems_.begin(), origin.elems_.end(),
                std::back_inserter(elems_)); 
}

Span::~Span(void) {}

Span &Span::operator=(const Span &rhs) {
    if (this == &rhs)
        return *this;
    elems_.reserve(rhs.elems_.capacity());
    size_ = rhs.size_;
    std::copy(rhs.elems_.begin(), rhs.elems_.end(),
               std::back_inserter(elems_));
    return *this;
}

void Span::addNumber(int i) {
    try {
        if (size_ <= elems_.size())
            throw std::length_error("[ Length Error ] container is full!");
        elems_.push_back(i);
    } catch(std::length_error &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Span::addRange(int first, int last) {
    try {
        if (static_cast<std::size_t>(std::abs(last - first)) > size_)
            throw std::length_error("[ Length Error ] container is full!");
        else if (first >= last)
            throw std::runtime_error("[ Range Error ] last number must be bigger than first!");

        for (; first != last; ++first)
            elems_.push_back(first);
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

std::size_t Span::shortestSpan(void) const {
    if (elems_.size() <= 1)
        throw std::runtime_error("[ Span Error ] container must have more than one!");
    Span temp = *this;

    std::sort(temp.elems_.begin(), temp.elems_.end());
    std::adjacent_difference(temp.elems_.begin(), temp.elems_.end(), temp.elems_.begin());
    std::size_t shortest_val = std::abs(*std::min_element(++temp.elems_.begin(),
                                temp.elems_.end()));
    return shortest_val;
}

std::size_t Span::longestSpan(void) const {
    if (elems_.size() <= 1)
        throw std::runtime_error("[ Span Error ] container must have more than one!");
    int highest_val = *std::max_element(elems_.begin(), elems_.end());
    int lowest_val = *std::min_element(elems_.begin(), elems_.end());
    return static_cast<std::size_t>(std::abs(highest_val - lowest_val));
}
