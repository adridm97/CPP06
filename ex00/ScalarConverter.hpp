/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:44:59 by aduenas-          #+#    #+#             */
/*   Updated: 2025/01/27 21:01:48 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <cmath>
#include <iostream>
#include <string>
#include <stdexcept>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
		static bool isChar(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);
		static int stringToInt(const std::string &input);
		static float stringToFloat(const std::string &input);
		static double stringToDouble(const std::string &input);
	public:
		static void convert(const std::string &literal);
};

#endif
