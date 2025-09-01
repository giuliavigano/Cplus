/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:30:38 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:30:39 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Replace.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 4){
		std::cout << "Not enough parameters!"
				  << "You need to insert <filename> <s1> <s2>"
				  << std::endl;
		return 1;
	}
	std::string	filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	Replace replacer(filename, s1, s2);
	if (!replacer.performReplace()) {
		return 1;
	}
	return 0;
}
