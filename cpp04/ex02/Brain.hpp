/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:14:09 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 13:14:10 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>
#include <iostream>

class Brain {
public:
	Brain(void);
	Brain(const std::string& idea);
	Brain(const Brain& value);
	Brain &operator=(const Brain& val);
	~Brain(void);
private:
	std::string ideas[100];
};

#endif