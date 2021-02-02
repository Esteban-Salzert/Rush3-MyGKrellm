/*
** EPITECH PROJECT, 2021
** core.cpp
** File description:
** produce
*/

#include "date_time.hpp"
#include <sstream>
#include <chrono>
#include <ctime>

Date_Time::Date_Time()
{
    this->time = "";
}

Date_Time::~Date_Time()
{}

std::string Date_Time::getTime() const
{
    return (this->time);
}

void Date_Time::setTime(std::string time)
{
    this->time = time;
}

bool Date_Time::get_info()
{
    std::string tmp(30, '\0');
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    std::strftime(&tmp[0], tmp.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
    this->time = tmp;
    return (true);
}
