/*
** EPITECH PROJECT, 2019
** B_CPP_300_BDX_3_1_CPPrush3_victor_miot
** File description:
** 
*/
#ifndef B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_NETWORK_HPP
#define B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_NETWORK_HPP

#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

class Network {
public:
    Network();
    ~Network();

    std::string getReceivepacket() const;
    std::string getReceivebytes() const;
    std::string getTransmitbytes() const;
    std::string getTransmitpacket() const;

    bool getInfo();

private:
    std::string receive_packet;
    std::string receive_bytes;
    std::string transmit_bytes;
    std::string transmit_packet;
};
#endif //B_CPP_300_BDX_3_1_CPPRUSH3_VICTOR_MIOT_NETWORK_HPP
