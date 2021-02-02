/*
** EPITECH PROJECT, 2021
** core.cpp
** File description:
** produce
*/

#include "memory_ram.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>

Memory::Memory()
{
    this->memory_free = 0;
    this->memory_total = 0;
    this->swap_free = 0;
    this->swap_total = 0; 
}

Memory::~Memory()
{}

void Memory::setMemory_total(int mem)
{
    this->memory_total = mem;
}

void Memory::setMemory_free(int mem)
{
    this->memory_free = mem;
}

void Memory::setSwap_free(int mem)
{
    this->swap_free = mem;
}

void Memory::setSwap_total(int mem)
{
    this->swap_total = mem;
}

int Memory::getMemory_used() const
{
    return (((this->memory_total - this->memory_free) * 100) / this->memory_total);
}

int Memory::getMemory_free() const
{
    return (this->memory_free);
}

int Memory::getMemory_total() const
{
    return (this->memory_total);
}

int Memory::getSwap_used() const
{
    if (this->swap_total == 0) return 0;
    return (((this->swap_total - this->swap_free)* 100) / this->swap_total);
}

int Memory::getSwap_free() const
{
    return (this->swap_free);
}

int Memory::getSwap_total() const
{
    return (this->swap_total);
}

std::string removeSpac(std::string type)                                       
{
    type.erase(std::remove(type.begin(), type.end(), ' '), type.end());
    return (type);
}

bool Memory::get_Info()
{
    std::ifstream file("/proc/meminfo");
    std::unordered_map<std::string, int> info;
    std::string line;
    std::string name;
    std::string values;
    int value;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::stringstream(line) >> name;
            values = line.substr(line.find(':')+1, line.size());
            values = values.substr(0, values.find("kB")-1);
            values = removeSpac(values);
            value = std::atof(values.c_str());
            std::pair<std::string, int> tmp(name.substr(0, name.size()-1), value);
            info.insert(tmp);
        }
        this->setMemory_free(info["MemAvailable"]);
        this->setMemory_total(info["MemTotal"]);
        this->setSwap_free(info["SwapFree"]);
        this->setSwap_total(info["SwapTotal"]);
        file.close();
        return (true);
    }
    return (false);
}
