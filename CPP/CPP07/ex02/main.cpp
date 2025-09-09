#include <iostream>
#include "Array.hpp"
#include <cstdlib> // pour rand() et srand()
#include <ctime>   // pour time()
#include <string>

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    {
        std::cout << "\n>> TEST DEFAULT VALUE INIT :\n" << std::endl;
        std::cout << ">> std::string :" << std::endl;
        Array<std::string> string(5);
        std::cout << "|" << string[0] << "|" << std::endl;
        std::cout << "|" << string[1] << "|" << std::endl;
        std::cout << "|" << string[2] << "|" << std::endl;
        std::cout << "|" << string[3] << "|" << std::endl;
        std::cout << "|" << string[4] << "|" << std::endl;

        std::cout << ">> char :" << std::endl;
        Array<char> c(5);
        std::cout << "|" << c[0] << "|" << std::endl;
        std::cout << "|" << c[1] << "|" << std::endl;
        std::cout << "|" << c[2] << "|" << std::endl;
        std::cout << "|" << c[3] << "|" << std::endl;
        std::cout << "|" << c[4] << "|" << std::endl;

        std::cout << ">> int :" << std::endl;
        Array<int> i(5);
        std::cout << "|" << i[0] << "|" << std::endl;
        std::cout << "|" << i[1] << "|" << std::endl;
        std::cout << "|" << i[2] << "|" << std::endl;
        std::cout << "|" << i[3] << "|" << std::endl;
        std::cout << "|" << i[4] << "|" << std::endl;
    }
    {
        std::cout << "\n>> TEST ARRAY NO PARAMETER CONSTRUCTOR :\n" << std::endl;
        Array<int> i;
        std::cout << ">> i size : " << i.size() << std::endl;
        try
        {
            std::cout << ">> value of i[0] when i is empty : " << std::endl;
            std::cout << i[0] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n>> TEST COPY CONSTRUCTOR :" << std::endl;
        Array<int> integer(5);
        for (int i = 0; i < 5; i++) {
            integer[i] = i;
        }
        Array<int> cpy(integer);
        Array<int> cpy2 = cpy;
        for (int i = 0; i < 5; i++) {
            std::cout << "\n>> integer[" << i << "] = " << integer[i] << std::endl;
            std::cout << ">> cpy[" << i << "] = " << cpy[i] << std::endl;
            std::cout << ">> cpy2[" << i << "] = " << cpy2[i] << std::endl;
        }
        std::cout << "\n>> integer[0] become 255" << std::endl;
        integer[0] = 255;
        std::cout << ">> integer[0] = " << integer[0] << std::endl;
        std::cout << ">> cpy[0] = " << cpy[0] << std::endl;
        std::cout << "\n>> cpy[0] become 636" << std::endl;
        cpy[1] = 636;
        std::cout << ">> integer[1] = " << integer[1] << std::endl;
        std::cout << ">> cpy[1] = " << cpy[1] << std::endl;
    }
    return 0;
}