/*
** EPITECH PROJECT, 2021
** hostname_username
** File description:
** produce
*/

#ifndef HOSTNAME_HPP_
#define HOSTNAME_HPP_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class Hostname_Username {
    public:
        Hostname_Username();
        ~Hostname_Username();
        std::string getHostname() const;
        std::string getUsername() const;
        void setHostname(std::string);
        void setUsername(std::string);
        bool get_info();

    private:
        std::string hostname;
        std::string username;
};

#endif /* !HOSTNAME_HPP_ */
