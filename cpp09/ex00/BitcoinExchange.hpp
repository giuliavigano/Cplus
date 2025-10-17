/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giuliaviga <giuliaviga@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:21:12 by gvigano           #+#    #+#             */
/*   Updated: 2025/10/17 16:00:36 by giuliaviga       ###   ########.fr       */
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

private:
	std::map<std::string, float>	database;

	bool	isValidDate(const std::string& date);
	bool	isValidValue(double value);
	bool	isAllDigits(const std::string& str);
	bool	isValidNumberStr(const std::string& str_value);
	std::string	findClosestDate(const std::string& date);
	std::string	trim(const std::string& value_str);
};

#endif