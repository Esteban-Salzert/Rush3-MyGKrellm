/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** system
*/

#include "date_time.h"
#include "hostname_username.h"
#include "memory_ram.h"
#include "core.hpp"
#include "Kernel.h"
#include "Network.h"

class System
{
    public:
        System() = default;
        ~System() = default;
        void fetchData() {
            time.get_info();
            user.get_info();
            mem.get_Info();
            CPU.get_file();
            _kernel.getInfo();
            _network.getInfo();
        };
        Date_Time time;
        Hostname_Username user;
        Memory mem;
        Core CPU;
        Kernel _kernel;
        Network _network;
};
