/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:32:15 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 16:20:23 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_H_
# define REPLACER_H_

# include <string>
# include <fstream>

class Replacer {
public:
  Replacer(const std::string &filename);
  ~Replacer();
  bool Ok(void);
  void ShowErrorMessage(void);
  void Replace(const std::string &replace_from, const std::string &replace_to);

private:
  static const int kSuccess = 0;
  static const int kPending = 1;
  static const int kCannotOpenFile = 2;
  static const int kIOFail = 3;

  const std::string filename_;
  int status_;
  std::ifstream infile_;
  std::ofstream outfile_;
};

#endif