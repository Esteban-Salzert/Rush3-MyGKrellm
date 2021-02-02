/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** sys
*/

#include "monitor.hpp"

void draw_net(MonitorDisplay &disp, const System &sys)
{
    //indexes
    uint y = 1;
    uint x = 1;

    wclear(disp.wins[NET].win);
    box(disp.wins[NET].win, 0, 0);
    wprintw(disp.wins[NET].win, "Network Information");
    mvwprintw(disp.wins[NET].win, y++, x, "Packets:");
    mvwprintw(disp.wins[NET].win, y++, x, "Received:    %s", sys._network.getReceivepacket().data());
    mvwprintw(disp.wins[NET].win, y++, x, "Transmited:  %s", sys._network.getTransmitpacket().data());
    x += COLS / 2;
    y = 1;
    mvwprintw(disp.wins[NET].win, y++, x, "Bytes:");
    mvwprintw(disp.wins[NET].win, y++, x, "Received:    %s", sys._network.getReceivebytes().data());
    mvwprintw(disp.wins[NET].win, y++, x, "Transmited:  %s", sys._network.getTransmitbytes().data());
}
