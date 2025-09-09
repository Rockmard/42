/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/15 20:45:13 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }
    std::cout << std::endl;
    {
        Intern someRandomIntern;
        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *scf << std::endl;
        delete scf;
    }
    std::cout << std::endl;
    {
        Intern someRandomIntern;
        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
        std::cout << *ppf << std::endl;
        delete ppf;
    }
    std::cout << std::endl;
    {
        Intern someRandomIntern;
        AForm* f;
        try
        {
            f = someRandomIntern.makeForm("invalid request", "Bender");
        }
        catch(std::exception &e)
        {
            std::cerr << "Exception caught : " << e.what() << std::endl;
        }
    }
    return 0;
}