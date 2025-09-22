#include "ScalarConverter.hpp"

bool	ScalarConverter::isCharLiteral(const std::string& str) {
	return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool	ScalarConverter::isIntLiteral(const std::string& str) {
	size_t	start;

	if (str.empty())
		return false;
	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start++;
	if (start >= str.length())
		return false;
	for (size_t i = start; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isFloatLiteral(const std::string& str) {
	size_t dotPos;
	size_t start;
	std::string numPart;
	
	if (str.length() < 3 || str[str.length() - 1] != 'f')
		return false;
	numPart = str.substr(0, str.length() - 1);
	dotPos = numPart.find('.');
	if (dotPos == std::string::npos)
		return false;
	start = 0;
	if (numPart[0] == '+' || numPart[0] == '-')
		start = 1;
	if (start >= dotPos)
		return false;
	for (size_t i = start; i < dotPos; ++i) {
		if (!std::isdigit(numPart[i]))
			return false;
	}
	if (dotPos + 1 >= numPart.length())
		return false;
	for (size_t i = dotPos + 1; i < numPart.length(); ++i) {
		if (!std::isdigit(numPart[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isDoubleLiteral(const std::string& str) {
	size_t dotPos;
	size_t start;

	if (str.length() < 2 || str[str.length() - 1] == 'f')
		return false;
	dotPos = str.find('.');
	if (dotPos == std::string::npos)
		return false;
	start = 0;
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	if (start >= dotPos)
		return false;
	for (size_t i = start; i < dotPos; ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}
	if (dotPos + 1 >= str.length())
		return false;
	for (size_t i = dotPos + 1; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ScalarConverter::isSpecialValue(const std::string& str) {
	return (str == "nan" || str == "nanf" || 
			str == "+inf" || str == "-inf" ||
			str == "+inff" || str == "-inff");
}

char	ScalarConverter::parseChar(const std::string& str) {
	return str[1];
}

int		ScalarConverter::parseInt(const std::string& str) {
	return std::atoi(str.c_str());
}

float	ScalarConverter::parseFloat(const std::string& str) {
	return static_cast<float>(std::atof(str.c_str()));
}

double	ScalarConverter::parseDouble(const std::string& str) {
	return std::atof(str.c_str());
}

double	ScalarConverter::parseSpecialValue(const std::string& str) {
	return std::atof(str.c_str());
}

void	ScalarConverter::printChar(double value) {
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::printInt(double value) {
	if (std::isnan(value) || std::isinf(value))
		std::cout << "int: impossible" << std::endl;
	else if (value < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else if (value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value) {
	if (std::isnan(value))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(value)) {
		if (value > 0)
			std::cout << "float: inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else {
		float f = static_cast<float>(value);
		if (f == static_cast<int>(f)) {
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		} else {
			std::cout << "float: " << f << "f" << std::endl;
		}
	}
}

void	ScalarConverter::printDouble(double value) {
	if (std::isnan(value))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(value)) {
		if (value > 0)
			std::cout << "double: inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else {
		if (value == static_cast<int>(value)) {
			std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		} else {
			std::cout << "double: " << value << std::endl;
		}
	}
}

void	ScalarConverter::convert(const std::string& literal) {
	double	value;

	if (isSpecialValue(literal)) {
		value = parseSpecialValue(literal);
	}
	else if (isCharLiteral(literal)) {
		value = static_cast<double>(parseChar(literal));
	}
	else if (isIntLiteral(literal)) {
		value = static_cast<double>(parseInt(literal));
	}
	else if (isFloatLiteral(literal)) {
		value = static_cast<double>(parseFloat(literal));
	}
	else if (isDoubleLiteral(literal)) {
		value = parseDouble(literal);
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}