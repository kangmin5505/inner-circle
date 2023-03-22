/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:24:34 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/18 13:31:12 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_H_
# define MUTANT_STACK_H_

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
private:
    typedef typename std::stack<T>::container_type  Base_;

public:
    typedef typename Base_::iterator              iterator;
    typedef typename Base_::const_iterator        const_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator>       reverse_iterator;

    iterator begin(void) { return this->c.begin(); }
    iterator end(void) { return this->c.end(); }
    const_iterator cbegin(void) const { return this->c.cbegin(); }
    const_iterator cend(void) const { return this->c.cend(); }
    const_reverse_iterator rbegin(void) const { return this->c.rbegin(); }
    const_reverse_iterator rend(void) const { return this->c.rend(); }
    reverse_iterator rbegin(void) { return this->c.rbegin(); }
    reverse_iterator rend(void) { return this->c.rend(); }

};

#endif
