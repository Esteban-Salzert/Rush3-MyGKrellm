/*
** EPITECH PROJECT, 2019
** B-CPP-300-BDX-3-1-CPPrush3-victor.miot
** File description:
** 
*/
#include "Kernel.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <utility>

///////
////CTR DTR
///////

Kernel::Kernel()
{
    getInfo();
}

Kernel::~Kernel()
{

}

///////
////GETTER
///////

std::string Kernel::get_kernel_version() const
{
    return kernel_version;
}

std::string Kernel::get_operating_system() const
{
    return operating_system;
}

///////
////SETTER
///////

void Kernel::setKernel(std::string a)
{
    kernel_version = std::move(a);
}

void Kernel::setOperatingKernel(std::string a)
{
    operating_system = std::move(a);
}

///////
/////ACTION
///////

bool Kernel::getInfo()
{
    std::ifstream file("/proc/version");
    std::string content;
    if (file.is_open()) {
        std::getline(file, content);
        this->setOperatingKernel(content.substr(0, content.find_first_of(' ', 0)));
        content = &content[content.find_first_of(' ', 0) + 1];
        this->setKernel(content.substr(0, content.find_first_of('(', 0)));
        file.close();
        return true;
    }
    return false;
}
