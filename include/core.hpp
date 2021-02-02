/*
** EPITECH PROJECT, 2021
** core
** File description:
** produce
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

typedef struct s_core {
    std::string frequency;
    std::string frequency_max;
} core_t;

class Core {
    public:
        Core();
        ~Core();
        
        std::vector<core_t> getInfo_core() const;
        std::string getModel() const {
            return this->model;
        }
        void setInfo_core(std::string, std::string);
        bool get_file();

    private:
        std::string model;
        std::vector<core_t> core;
};

#endif /* !CORE_HPP_ */
