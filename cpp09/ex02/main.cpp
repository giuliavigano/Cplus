/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:06:33 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/22 12:06:33 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
    PmergeMe    jaco;
	if (jaco.parseInput(argc, argv)) {
        jaco.displayBefore();
        jaco.sortWithDeque();
        jaco.sortWithVector();
        jaco.displayAfter();
        jaco.displayTime();
    }
    return 0;
}