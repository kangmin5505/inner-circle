/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:15:25 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 15:31:26 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Parser.hpp"

Parser::Parser(int argc, char **argv)
  : argc_(argc), argv_(argv), status_(kPending) { }

void Parser::Parse(void) {
  if (argc_ != kNumberofArgs) {
    status_ = kWrongNumberOfArgs;
    return;
  }
  filename_ = argv_[1];
  if (filename_ == "") {
    status_ = kEmptyFilename;
    return;
  }
  s1_ = argv_[2];
  if (s1_ == "") {
    status_ = kEmptyS1;
    return;
  }
  s2_ = argv_[3];
  if (s2_ == "") {
    status_ = kEmptyS2;
    return;
  }
  status_ = kSuccess;
}

void Parser::ShowErrorMessage(void) {
  switch (status_) {
    case kWrongNumberOfArgs:
      std::cerr << "usage: ./sed [filename] [replace_from] [replace_to]"
                << std::endl;
      break;
    case kEmptyFilename:
      std::cerr << "[filename] field must not empty string" << std::endl;
      break;
    case kEmptyS1:
      std::cerr << "[replace_from] field must not empty string" << std::endl;
      break;
    case kEmptyS2:
      std::cerr << "[replace_to] field must not empty string" << std::endl;
      break;
    default:
      break;
  }
}

bool Parser::Ok(void) { return status_ == kSuccess; }

const std::string &Parser::filename(void) const { return filename_; }

const std::string &Parser::s1(void) const { return s1_; }

const std::string &Parser::s2(void) const { return s2_; }