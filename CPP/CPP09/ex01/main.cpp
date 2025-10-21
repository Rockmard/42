/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:27:47 by tpipi             #+#    #+#             */
/*   Updated: 2025/09/12 12:55:19 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cerr << "Error: the programm need only one argument." << std::endl;
    else {
        int res = ft_rpn(std::string(av[1]));

        switch (res) {
            case 1:
                std::cerr << "Error: an error in the characters' expression has been found." << std::endl;
                break;
            case 2:
                std::cerr << "Error: not enough number before operand." << std::endl;
                break;
            case 3:
                std::cerr << "Error: division by 0." << std::endl;
                break;
            case 4:
                std::cerr << "Error: the stack has more than 1 elements left after execution." << std::endl;
                break;
            default:
                return 0;
        }
    }
    return 0;
}
