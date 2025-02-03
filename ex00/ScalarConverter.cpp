/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:53:33 by aduenas-          #+#    #+#             */
/*   Updated: 2025/02/01 19:35:33 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return(*this);
}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &literal)
{
	try
	{
		if (isChar(literal))
		{
			char c = literal[0];
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
		}			
		else if (isInt(literal))
		{
			int i;
			i = stringToInt(literal);
			std::cout << "char: " << (i >= 32 && i <= 126 ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		}
		else if (isFloat(literal))
		{
			float f;
			f = stringToFloat(literal);
			std::cout << "char: " << (f < 0 || f > 127 || f != f ? "impossible" : (static_cast<int>(f) < 32 || static_cast<int>(f) > 126 ? "Non displayable" : "'" + std::string(1, static_cast<char>(f)) + "'")) << std::endl;
			std::ostringstream oss;
			if (std::isnan(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
				oss << "impossible";
			else
				oss << static_cast<int>(f);
			std::cout << "int: " << oss.str() << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
		}
		else if (isDouble(literal))
		{
			double d;
			d = stringToDouble(literal);
			std::cout << "char: " << (d < 0 || d > 127 || d != d ? "impossible" : (static_cast<int>(d) < 32 || static_cast<int>(d) > 126 ? "Non displayable" : "'" + std::string(1, static_cast<char>(d)) + "'")) << std::endl;
			std::ostringstream oss;
			if (std::isnan(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
				oss << "impossible";
			else
				oss << static_cast<int>(d);
			std::cout << "int: " << oss.str() << std::endl;
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
		else
			std::cout << "Error: invalid input." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &str)
{
	return (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]));
}
bool ScalarConverter::isInt(const std::string &input)
{
    if (input.empty() || (input[0] != '-' && input[0] != '+' && !isdigit(input[0])))
        return false;
    char *end;
    errno = 0;
	long num = strtol(input.c_str(), &end, 10);
    return *end == '\0' && errno == 0 && num >= INT_MIN && num <= INT_MAX;
}

bool ScalarConverter::isFloat(const std::string &input)
{
    if (input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
        return true;
    if (input.length() < 3 || input[input.length() - 1] != 'f')
		return false;
	std::string without_f = input.substr(0, input.length() - 1);
	return isDouble(without_f);
}

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty())
		return false;
	if (input == "nan" || input == "inf" || input == "-inf" || input == "+inf")
		return true;
	char *end;
	strtod(input.c_str(), &end);
	return *end == '\0';
}

int ScalarConverter::stringToInt(const std::string &input)
{
	char *end;
	return static_cast<int>(strtol(input.c_str(), &end, 10));
}

float ScalarConverter::stringToFloat(const std::string &input)
{
	char *end;
	return static_cast<float>(strtod(input.c_str(), &end));
}

double ScalarConverter::stringToDouble(const std::string &input)
{
	char *end;
	return strtod(input.c_str(), &end);
}
