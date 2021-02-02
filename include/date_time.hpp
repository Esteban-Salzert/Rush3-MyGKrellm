/*
** EPITECH PROJECT, 2021
** date
** File description:
** produce
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class Date_Time {
    public:
        Date_Time();
        ~Date_Time();
        std::string getTime() const;
        void setTime(std::string);
        bool get_info();

    private:
        std::string time;
};

#endif /* !DATE_HPP_ */
