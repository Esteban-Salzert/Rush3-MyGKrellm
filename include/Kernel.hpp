/*
** EPITECH PROJECT, 2019
** B-CPP-300-BDX-3-1-CPPrush3-victor.miot
** File description:
** 
*/
#ifndef B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_SYSTEM_HPP
#define B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_SYSTEM_HPP

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class Kernel {
public :
    Kernel();
    ~Kernel();

    void setKernel(std::string);
    void setOperatingKernel(std::string);

    std::string get_kernel_version() const;
    std::string get_operating_system() const;

    bool getInfo();

private:
//    enum OS {_WIN32,
//            __APPLE__,
//            __linux__};
    std::string kernel_version;
    std::string operating_system;

};

#endif //B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_SYSTEM_HPP
