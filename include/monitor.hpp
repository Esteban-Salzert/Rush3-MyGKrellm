/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** monitor
*/

#include <map>
#include <string>
#include <ncurses.h>
#include "System.hpp"

enum color_pairs {
    BLACK = 1,
    RED = 2,
    GREEN = 3,
    YELLOW = 4,
    BLUE = 5,
    MAGENTA = 6,
    CYAN = 7,
    WHITE = 8
};

enum win_type{
    INFO,
    CPU,
    RAM,
    NET,
    SET
};

class Module
{
    public:
        Module(int h = 0, int w = 0, int y = 0, int x = 0, WINDOW *win = nullptr)
        {
            this->width = w;
            this->height = h;
            this->posX = x;
            this->posY = y;
            this->win = win;
        };
        ~Module() = default;
        unsigned int posX = 0;
        unsigned int posY = 0;
        unsigned int height = 0;
        unsigned int width = 0;
        WINDOW *win;
};

class Settings
{
    public:
        bool INFOdisp = true;
        bool CPUdisp = true;
        bool RAMdisp = true;
        bool NETdisp = true;
        bool SETdisp = false;
};

class MonitorDisplay
{
    public:
        unsigned int screen_height;
        unsigned int screen_width;
        std::map<const win_type, Module> wins;
        Settings settings;
};
