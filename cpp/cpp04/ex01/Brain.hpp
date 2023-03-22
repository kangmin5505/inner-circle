/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:20:19 by kangkim           #+#    #+#             */
/*   Updated: 2022/04/07 01:31:19 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H_
# define BRAIN_H_

# include <string>

class Brain {
public:
  Brain();
  Brain(const Brain &origin);
  ~Brain();
  Brain &operator=(const Brain &rhs);

  std::string &operator[](int i);
  void set_idea(int i, const std::string &idea);
  const std::string &get_idea(int i) const;

  static const int kMaxIdeas = 100;

private:
  std::string ideas_[kMaxIdeas];
};

#endif
