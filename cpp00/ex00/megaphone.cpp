/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:28:09 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 10:28:11 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++){
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++){
			std::cout << (char)std::toupper(arg[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}