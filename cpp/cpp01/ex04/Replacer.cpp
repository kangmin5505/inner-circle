/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:53:12 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 16:58:41 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

#include "Replacer.hpp"


Replacer::Replacer(const std::string &filename)
  : status_(kPending)
{
    infile_.open(filename);
    if (not infile_.good()) {
      status_ = kCannotOpenFile;
      return;
    }
    outfile_.open(filename + ".replace");
    if (not outfile_.good()) {
      status_ = kCannotOpenFile;
      return;
    }
}

Replacer::~Replacer(void) {
  if (infile_.is_open()) infile_.close();
  if (outfile_.is_open()) outfile_.close();
}

void Replacer::ShowErrorMessage(void) {
  switch (status_) {
    case kCannotOpenFile:
      std::cerr << "sed: Cannot open file" << std::endl;
      break;
    case kIOFail:
      std::cerr << "sed: I/O error occurred" << std::endl;
      break;
    default:
      break;
  }
}

void Replacer::Replace(const std::string &replace_from, const std::string &replace_to) {
  std::ostringstream oss;

  oss << infile_.rdbuf();
  std::string file_contexts = oss.str();
  for (size_t last = 0, curr;; last = curr + replace_from.length()) {
    curr = file_contexts.find(replace_from, last);
    if (curr == std::string::npos) {
      outfile_ << file_contexts.substr(last);
      break;
    }
    outfile_ << file_contexts.substr(last, curr - last);
    outfile_ << replace_to;
  }
  if (outfile_.bad()) {
    status_ = kIOFail;
  }
  else {
    status_ = kSuccess;
  }
}

bool Replacer::Ok(void) { return status_ == kSuccess || status_ == kPending; }