/*
** EPITECH PROJECT, 2021
** core.cpp
** File description:
** produce
*/

#include "core.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include <unordered_map>

Core::Core()
{
}

Core::~Core()
{
    this->core.clear();
}

std::vector<core_t> Core::getInfo_core() const
{
    return (this->core);
}

void Core::setInfo_core(std::string m, std::string frec)
{
    core_t core;

    core.frequency = frec;
    this->model = m;
    this->core.push_back(core);
}

std::string removeSpace(std::string type)
{
    type.erase(std::remove(type.begin(), type.end(), '\t'), type.end());
    return (type);
}

std::string getCpumax()
{
    std::system("lscpu > cpumax.txt");
    std::ifstream file("cpumax.txt");
    std::string line;
    std::string value;
    int i = 0;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (i == 16) {
                value = line.substr(line.find(':') + 2, line.size());
                value = value.substr(0, value.size() -1);
            }
            i++;
        }
    }
    file.close();
    std::remove("cpumax.txt");
    return (value);
}

bool Core::get_file()
{
    std::ifstream file("/proc/cpuinfo");
    core_t core;
    std::string line;
    std::string type;
    std::string value;
    std::string val;
    int tmp = 0;
    int i = 0;
    unsigned long finder = 0;

    this->core.clear();
    if (file.is_open()) {
        while (std::getline(file, line)) {
            finder = line.find(':', 0);
            type = removeSpace(line.substr(0, finder));
            if (finder != line.size() - 1)
                value = line.substr(finder + 2, line.size());
            else
                value = "";
            std::istringstream iss(value);
            iss >> tmp;
            if (tmp == i+1) {
                this->core.push_back(core);
                i++;
            }
            if (type.compare(0, 10,"model name") == 0) {
                this->model = value;
                core.frequency_max = getCpumax();
            }
            if (type.compare(0, 7,"cpu MHz") == 0)
                core.frequency = value;
        }
        file.close();
    } else {
        return (false);
    }
    return (true); 
}
