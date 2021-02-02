/*
** EPITECH PROJECT, 2021
** memory
** File description:
** produce
*/

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class Memory {
    public:
        Memory();
        ~Memory();
        
        void setSwap_total(int);
        void setSwap_free(int);
        void setMemory_total(int);
        void setMemory_free(int);
        
        int getMemory_used() const;
        int getMemory_total() const;
        int getMemory_free() const;
        int getSwap_used() const;
        int getSwap_free() const;
        int getSwap_total() const;

        bool get_Info();

    private:
        int memory_total;
        int memory_free;
        int swap_total;
        int swap_free;
};

#endif /* !MEMORY_HPP_ */
