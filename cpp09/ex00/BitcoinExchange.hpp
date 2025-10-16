/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:21:12 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/16 16:21:13 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <exception>


class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& value);
	BitcoinExchange&	operator=(const BitcoinExchange& val);
	~BitcoinExchange();

	void	loadDatabase();
	void	parse_input(const std::string& input);
	float	get_exchange_value(const std::string& date);

	class ErrorOpeningThisFile : std::exception {
	public:
		virtual const char* what() const throw() {
			return "Error: could not open file.";
		}
	};

	// class NotAValidNumber : std::exception {
	// public:
	// 	virtual const char* what() const throw() {
	// 		return "Error: not a valid number (must be a valid positive number)!";
	// 	}
	// };

	// class NumberTooLarge : std::exception {
	// public:
	// 	virtual const char* what() const throw() {
	// 		return "Error: too large number (>1000) !";
	// 	}
	// };

	// class NotAValidDate : std::exception {
	// public:
	// 	virtual const char* what() const throw() {
	// 		return "Error: not a valid date!";
	// 	}
	// };

private:
	std::map<std::string, float>	database;

	bool	isValidDate(const std::string& date);
	bool	isValidValue(double value);
	bool	isValidNumberStr(const std::string& str_value);
	std::string	findClosestDate(const std::string& date);
	std::string	trim(const std::string& value_str);
};

#endif