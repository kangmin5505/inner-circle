/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:59:52 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/18 10:59:29 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H_
# define SPAN_H_

# include <vector>

class Span {
public:
    Span(const std::size_t &size);
    Span(const Span &origin);
    ~Span(void);
    Span &operator=(const Span &rhs);

    void addNumber(int i);
    void addRange(int i, int j);
    std::size_t shortestSpan(void) const;
    std::size_t longestSpan(void) const;

private:
    Span(void);

    std::vector<int> elems_;
    std::size_t size_;
};

#endif
