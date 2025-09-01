/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:30:41 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:30:42 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <iostream>
#include <fstream>

Replace::Replace(std::string filename, std::string s1, std::string s2) 
	: filename(filename), s1(s1), s2(s2) {}

std::string Replace::replaceOccurrence(const std::string& line, const std::string& s1, const std::string& s2) {
	std::string replaced;
	size_t found;
	size_t pos = 0;

	while ((found = line.find(s1, pos)) != std::string::npos) {
		replaced += line.substr(pos, found - pos);
		replaced += s2;
		pos = found + s1.length();
	}
	replaced += line.substr(pos);
	return replaced;
}

bool Replace::performReplace() {
	if (s1.empty()) {
		std::cout << "Error: s1 cannot be an empty string." << std::endl;
		return false;
	}
	std::ifstream infile(filename.c_str());
	if (!infile.is_open()) {
		std::cout << "Error with opening file: " << filename << std::endl;
		return false;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cout << "Error with creating file: " << filename << ".replace" << std::endl;
		infile.close();
		return false;
	}
	std::string line;
	while (std::getline(infile, line)) {
		outfile << replaceOccurrence(line, s1, s2) << std::endl;
	}
	infile.close();
	outfile.close();
	return true;
}