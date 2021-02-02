/*
** EPITECH PROJECT, 2021
** core.cpp
** File description:
** produce
*/

#include "hostname_username.h"
#include <sstream>
#include <chrono>
#include <ctime>

Hostname_Username::Hostname_Username()
{
    this->hostname = "";
    this->username = "";
}

Hostname_Username::~Hostname_Username()
{}

std::string Hostname_Username::getHostname() const
{
    return (this->hostname);
}

std::string Hostname_Username::getUsername() const
{
    return (this->username);
}

void Hostname_Username::setHostname(std::string host)
{
    this->hostname = host;
}

void Hostname_Username::setUsername(std::string user)
{
    this->username = user;
}

bool Hostname_Username::get_info()
{
    char *user = std::getenv("USER");
    this->username = user ? user : "";
    char *host = std::getenv("HOSTNAME");
    this->hostname = host ? host : user;
    return (true);
}
