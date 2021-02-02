/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** main_curse
*/

#include <time.h>
#include <iostream>
#include <unistd.h>
#include "curse.hpp"
#include "monitor.hpp"

#define ever (;;)

void window_init(void);
void init_monitor(MonitorDisplay &disp, const System &sys);
void draw_sys(MonitorDisplay &disp, const System &sys);
void draw_cpu(MonitorDisplay &disp, const System &sys);
void draw_ram(MonitorDisplay &disp, const System &sys);
void draw_net(MonitorDisplay &disp, const System &sys);
void draw_settings(MonitorDisplay &disp, const System &sys);

void draw_elems(MonitorDisplay &disp, const System &sys)
{
    if (disp.wins[INFO].win && disp.settings.INFOdisp) draw_sys(disp, sys);
    if (disp.wins[CPU].win && disp.settings.CPUdisp) draw_cpu(disp, sys);
    if (disp.wins[RAM].win && disp.settings.RAMdisp) draw_ram(disp, sys);
    if (disp.wins[NET].win && disp.settings.NETdisp) draw_net(disp, sys);
    if (disp.wins[SET].win && disp.settings.SETdisp) draw_settings(disp, sys);
    mvwprintw(stdscr, LINES - 1, 0, "QUIT: q | SETTINGS: o");
}

void update(MonitorDisplay &disp, System &sys)
{
    unsigned int width = 0;
    unsigned int height = 0;
    sys.fetchData();
    clear();
    draw_elems(disp, sys);
    getmaxyx(stdscr, width, height);
    disp.screen_width = width;
    disp.screen_height = height;
    refresh(); /* refresh windows */
    wrefresh(disp.wins[INFO].win);
    wrefresh(disp.wins[CPU].win);
    wrefresh(disp.wins[RAM].win);
    wrefresh(disp.wins[NET].win);
    wrefresh(disp.wins[SET].win);
}

bool check_param(MonitorDisplay &disp, char c);

void game_loop(MonitorDisplay &disp, System &sys)
{
    clock_t t1;
    t1 = clock();
    int c = 0;
    update(disp, sys);
    for ever {
        if (c == 'q')
            break;
        if (c == KEY_RESIZE) {
            update(disp, sys); /* update window (responsive mode) */
        }
        clock_t t2 = clock();
        if (1000.0 * ( t2 - t1 ) / CLOCKS_PER_SEC > 2000) { // update every 2 seconds (2000 milliseconds)
            t1 = clock();
            update(disp, sys);
        }
        if (c == 'o') {
            disp.settings.SETdisp = !disp.settings.SETdisp;
            update(disp, sys);
        }
        if (disp.settings.SETdisp && c != -1) {
            if (check_param(disp, c)) {
                update(disp, sys);
            }
        }
        c = getch();
    }
}

int main_curse(System &sys)
{
    MonitorDisplay disp;

    window_init();
    init_monitor(disp, sys);
    game_loop(disp, sys);
    
    delwin(stdscr);
    endwin(); /* end curse session */
    return 0;
}
