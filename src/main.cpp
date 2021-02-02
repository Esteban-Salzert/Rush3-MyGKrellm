/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** main
*/

#include <string>
#include <iostream>
#include "System.h"

int main_curse(System &sys);

int main(int argc, char **argv)
{
    if (argc != 2 || (std::string)argv[1] == "-h" || (std::string)argv[1] == "--help") {
        std::cout   << "usage: ./dabtop [-t|-g]" << std::endl
                    << "    arg:    -t: start dabtop in terminal mode" << std::endl
                    << "    arg:    -g: start dabtop in graphical mode" << std::endl;
        return 1;
    }
    System sys;
    sys.fetchData();
    std::string arg = (std::string)argv[1];
    if (arg == "-t") {
        std:: cout << "start dabtop in terminal mode" << std::endl;
        main_curse(sys);
    } else if (arg == "-g") {
        std::cout << "Starting dabtop in graphical mode..." << std::endl;
    } else {
        std::cerr << "Invalid argument: " << arg << std::endl;
        std::cerr << "Use [./dabtop --help] for more information." << std::endl;
    }
}
