/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:22 by tpipi             #+#    #+#             */
/*   Updated: 2025/06/04 13:19:18 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    {
        ShrubberyCreationForm   scform("default");
        std::cout << scform << std::endl;
        Bureaucrat  bCanSign("Bur", 145);
        Bureaucrat  bCantSign("Bur", 146);
        Bureaucrat  bCanExec("Bur", 137);
        Bureaucrat  bCantExec("Bur", 138);

        try
        {
            std::cout << "Test d'executer avec un bureaucrat sans avoir signer" << std::endl;
            scform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang inferieur" << std::endl;
            scform.beSigned(bCantSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang egal" << std::endl;
            scform.beSigned(bCanSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang inferieur" << std::endl;
            scform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang egal" << std::endl;
            scform.execute(bCanExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        RobotomyRequestForm   rrform("default");
        std::cout << "\n\n" << rrform << std::endl;
        Bureaucrat  bCanSign("Bur", 72);
        Bureaucrat  bCantSign("Bur", 73);
        Bureaucrat  bCanExec("Bur", 45);
        Bureaucrat  bCantExec("Bur", 46);

        try
        {
            std::cout << "Test d'executer avec un bureaucrat sans avoir signer" << std::endl;
            rrform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang inferieur" << std::endl;
            rrform.beSigned(bCantSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang egal" << std::endl;
            rrform.beSigned(bCanSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang inferieur" << std::endl;
            rrform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang egal" << std::endl;
            rrform.execute(bCanExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        
        std::cout << "\nTest d'executer plusieurs fois le RobotomyRequestForm sans avoir la meme reponse\n" << std::endl;
        rrform.execute(bCanExec);
        rrform.execute(bCanExec);
        rrform.execute(bCanExec);
        rrform.execute(bCanExec);
        rrform.execute(bCanExec);
    }

    {
        PresidentialPardonForm   ppform("default");
        std::cout << "\n\n" << ppform << std::endl;
        Bureaucrat  bCanSign("Bur", 25);
        Bureaucrat  bCantSign("Bur", 26);
        Bureaucrat  bCanExec("Bur", 5);
        Bureaucrat  bCantExec("Bur", 6);

        try
        {
            std::cout << "Test d'executer avec un bureaucrat sans avoir signer" << std::endl;
            ppform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang inferieur" << std::endl;
            ppform.beSigned(bCantSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test de signer avec un bureaucrat avec un rang egal" << std::endl;
            ppform.beSigned(bCanSign);
            std::cout << "Le form a ete signe" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang inferieur" << std::endl;
            ppform.execute(bCantExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            std::cout << "Test d'executer avec un bureaucrat avec un rang egal" << std::endl;
            ppform.execute(bCanExec);
            std::cout << "Le form a ete execute" << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}