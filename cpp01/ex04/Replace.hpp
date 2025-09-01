/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:30:44 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:30:44 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP
#include <string>

class Replace {
public:
	Replace(std::string filename, std::string s1, std::string s2);
	bool performReplace();
	static std::string replaceOccurrence(const std::string& line, const std::string& s1, const std::string& s2);
private:
	std::string filename;
	std::string s1;
	std::string s2;
};

#endif