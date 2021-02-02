/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** settings
*/

#include "monitor.hpp"

void draw_settings(MonitorDisplay &disp, const System &sys)
{
    (void)sys;
    wclear(disp.wins[SET].win);
    box(disp.wins[SET].win, 0, 0);
    wprintw(disp.wins[SET].win, "Display Settings (press 1/2/3/4 key to edit)");
    mvwprintw(disp.wins[SET].win, 1, 1, "System Pannel: [%c]", disp.settings.INFOdisp ? 'O' : 'X');
    mvwprintw(disp.wins[SET].win, 2, 1, "CPU Pannel:    [%c]", disp.settings.CPUdisp ? 'O' : 'X');
    mvwprintw(disp.wins[SET].win, 1, COLS / 4, "Memory Pannel:  [%c]", disp.settings.RAMdisp ? 'O' : 'X');
    mvwprintw(disp.wins[SET].win, 2, COLS / 4, "Network Pannel: [%c]", disp.settings.NETdisp ? 'O' : 'X');
}

bool check_param(MonitorDisplay &disp, char c)
{
    switch(c) {
        case '1':
            disp.settings.INFOdisp = !disp.settings.INFOdisp;
            break;
        case '2':
            disp.settings.CPUdisp = !disp.settings.CPUdisp;
            break;
        case '3':
            disp.settings.RAMdisp = !disp.settings.RAMdisp;
            break;
        case '4':
            disp.settings.NETdisp = !disp.settings.NETdisp;
            break;
        default:
            return false;
    }
    mvwin(disp.wins[INFO].win, 0, 0);
    mvwin(disp.wins[CPU].win, disp.settings.INFOdisp ? disp.wins[INFO].height : 0, 0);
    mvwin(disp.wins[RAM].win, (disp.settings.INFOdisp ? disp.wins[INFO].height : 0)
                                + (disp.settings.CPUdisp ? disp.wins[CPU].height : 0), 0);
    mvwin(disp.wins[NET].win, (disp.settings.INFOdisp ? disp.wins[INFO].height : 0)
                                + (disp.settings.CPUdisp ? disp.wins[CPU].height : 0)
                                + (disp.settings.RAMdisp ? disp.wins[RAM].height : 0), 0);
    return true;
}
