#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <cmath> // isnan, isinf
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib> // atoi, atof
#include <iomanip> // set precision
#include <iostream>


// Non-instantiable class: no data member, only static method, private constructor/destructor
class ScalarConverter {
public:
	static void	convert(const std::string& literal);
private:
	ScalarConverter();
	
	static bool	isCharLiteral(const std::string& str);
	static bool	isIntLiteral(const std::string& str);
	static bool isFloatLiteral(const std::string& str);
	static bool isSpecialValue(const std::string& str);
	static bool isDoubleLiteral(const std::string& str);

	static char		parseChar(const std::string& str);
	static int		parseInt(const std::string& str);
	static float	parseFloat(const std::string& str);
	static double	parseDouble(const std::string& str);
	static double	parseSpecialValue(const std::string& str);

	static void		printChar(double value);
	static void 	printInt(double value);
	static void		printFloat(double value);
	static void		printDouble(double value);
};

#endif