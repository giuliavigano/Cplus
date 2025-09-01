/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:28:51 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:28:52 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* p = &str;
	std::string& ref = str;
	std::cout << "memory address of the string: " << &str << std::endl;
	std::cout << "memory address of the pointer: " << p << std::endl;
	std::cout << "memory address of the reference: " << &ref << std::endl;
	std::cout << "value of the string: " << str << std::endl;
	std::cout << "value of the pointer: " << *p << std::endl;
	std::cout << "value of the reference: " << ref << std::endl;
	return 0;
}