/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:59:08 by adrian            #+#    #+#             */
/*   Updated: 2025/02/02 18:12:52 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    srand(time(0));
    Base* obj = generate();

    std::cout << "Identificación por puntero: ";
    identify(obj);
    std::cout << "Identificación por referencia: ";
    identify(*obj);
    delete obj;
    return 0;
}