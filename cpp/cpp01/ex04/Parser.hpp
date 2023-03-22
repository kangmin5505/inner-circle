/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:08:33 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 15:39:13 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H_
# define PARSER_H_

# include <string>

class Parser {
public:
  Parser(int argc, char **argv);
  void Parse(void);
  bool Ok(void);
  void ShowErrorMessage(void);
  const std::string &filename(void) const;
  const std::string &s1(void) const;
  const std::string &s2(void) const;

private:
  static const int kSuccess = 0;
  static const int kPending = 1;
  static const int kWrongNumberOfArgs = 2;
  static const int kEmptyFilename = 3;
  static const int kEmptyS1 = 4;
  static const int kEmptyS2 = 5;
  static const int kNumberofArgs = 4;

  std::string filename_;
  std::string s1_;
  std::string s2_;

  int argc_;
  char **argv_;
  int status_;
};

#endif