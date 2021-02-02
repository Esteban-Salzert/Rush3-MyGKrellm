/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** ram
*/

#include "monitor.h"

void draw_ram(MonitorDisplay &disp, const System &sys)
{
    wclear(disp.wins[RAM].win);
    box(disp.wins[RAM].win, 0, 0);
    wprintw(disp.wins[RAM].win, "RAM");
    int RAMuse = sys.mem.getMemory_used();
    int SWPuse = sys.mem.getSwap_used();
    int posX = 2;
    int mid = COLS / 2 + 1;
    int RAMobj = ((float)COLS / 2 - 18) * ((float)RAMuse / 100);
    int SWPobj = ((float)COLS / 2 - 18) * ((float)SWPuse / 100);

    mvwprintw(disp.wins[RAM].win, 1, posX, "%3s", "Mem");
    mvwprintw(disp.wins[RAM].win, 1, mid, "%3s", "Swp");
    posX += 4;
    mid += 4;
    mvwaddch(disp.wins[RAM].win, 1, posX, '[');
    mvwaddch(disp.wins[RAM].win, 1, mid, '[');
    for (int i = 0; i < RAMobj; i++) {
        mvwaddch(disp.wins[RAM].win, 1, posX + i + 1, ACS_CKBOARD);
    }
    for (int i = 0; i < SWPobj; i++) {
        mvwaddch(disp.wins[RAM].win, 1, mid + i + 1, ACS_CKBOARD);
    }
    mvwprintw(disp.wins[RAM].win, 1, posX + (COLS / 2 - 17), "%.1f/%.1fG]", (sys.mem.getMemory_total() - sys.mem.getMemory_free()) / 1000000.0, sys.mem.getMemory_total() / 1000000.0);
    mvwprintw(disp.wins[RAM].win, 1, mid + (COLS / 2 - 17), "%.1f/%.1fG]", (sys.mem.getSwap_total() - sys.mem.getSwap_free()) / 1000000.0, sys.mem.getSwap_total() / 1000000.0);
}
