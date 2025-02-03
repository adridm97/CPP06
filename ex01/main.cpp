/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:27:19 by adrian            #+#    #+#             */
/*   Updated: 2025/02/02 17:28:59 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.id = 42;
    data.name = "Test Data";

    std::cout << "Original Data pointer: " << &data << std::endl;
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;
    Data *deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserialized << std::endl;
    if (deserialized == &data)
        std::cout << "Success: The deserialized pointer matches the original." << std::endl;
    else
        std::cout << "Error: The deserialized pointer does not match the original." << std::endl;
    return 0;
}