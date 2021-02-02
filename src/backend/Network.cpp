/*
** EPITECH PROJECT, 2019
** B_CPP_300_BDX_3_1_CPPrush3_victor_miot
** File description:
** network
*/
#include "Network.h"
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <cstring>

/////
///CTR DTR
/////

Network::Network()
{
    getInfo();
}

Network::~Network()
{

}

/////
////GETTER
/////

std::string Network::getReceivebytes() const
{
    return (this->receive_bytes);
}

std::string Network::getReceivepacket() const
{
    return (this->receive_packet);
}

std::string Network::getTransmitbytes() const
{
    return (this->transmit_bytes);
}

std::string Network::getTransmitpacket() const
{
    return (this->transmit_packet);
}

/////
////ACTION
/////

std::string getWlo()
{
    std::system("cat /proc/net/dev > dev.txt");
    std::ifstream file("dev.txt");
    std::string line;
    std::string comp;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            comp = line.substr(0, 2);
            if (comp == "wl")
                break;
        }
    }
    file.close();
    std::remove("dev.txt");
    return (line);
}

bool Network::getInfo()
{
    std::string line = getWlo();
    std::string bytes;
    std::string packets;
    int i = 2;

    this->receive_bytes = "";
    this->receive_packet = "";
    this->transmit_bytes = "";
    this->transmit_packet = "";
    while (line[i] != ' ') {
        i++;
    }
    i++;
    while (line[i] != ' ') {
        this->receive_bytes += line[i];
        i++;
    }
    while (line[i] == ' ') {
        i++;
    }
    while (line[i] != ' ') {
        this->receive_packet += line[i];
        i++;
    }
    while (line[i] == ' ' || line[i] == '0') {
        i++;
    }
    while (line[i] != ' ') {
        this->transmit_bytes += line[i];
        i++;
    }
    while (line[i] == ' ') {
        i++;
    }
    while (line[i] != ' ') {
        this->transmit_packet += line[i];
        i++;
    }
    return (true);
}
