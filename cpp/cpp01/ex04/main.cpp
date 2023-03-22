/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:14:07 by kangkim           #+#    #+#             */
/*   Updated: 2022/03/27 16:54:58 by kangkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Replacer.hpp"

int main(int argc, char **argv) {
  Parser parser(argc, argv);

  parser.Parse();
  if (not parser.Ok()) {
    parser.ShowErrorMessage();
    return EXIT_FAILURE;
  }
  Replacer replacer(parser.filename());
  if (not replacer.Ok()) {
    replacer.ShowErrorMessage();
    return EXIT_FAILURE;
  }
  replacer.Replace(parser.s1(), parser.s2());
  if (not replacer.Ok()) {
    replacer.ShowErrorMessage();
    return EXIT_FAILURE;
  }
  return 0;
}