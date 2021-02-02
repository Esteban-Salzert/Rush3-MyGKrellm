/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** setup
*/

#include "curse.h"
#include <curses.h>
#include "monitor.h"

void window_init(void)
{
    initscr(); /* start curse session */
    keypad(stdscr, true); /* enable special input like F1, arrow keys... */
    nodelay(stdscr, true); /* true cause getch() to be a non-blocking call */
    cbreak(); /* [raw|cbreak] raw let you handle sig, cbreak let the terminal interpret it */
    noecho(); /* dont echo characters typed by users */
    curs_set(0); /* hide cursor */
    if(has_colors() == TRUE){
        start_color();
	}
}

Module create_Module(int height, int width, int y, int x)
{
    Module m(height, width, y, x, newwin(height, width, y, x));
    return m;
}

void init_monitor(MonitorDisplay &disp, const System &sys)
{
    getmaxyx(stdscr, disp.screen_width, disp.screen_height);
    disp.wins[INFO] = create_Module( 6,      //height
                                    COLS,   //width
                                    0,      //pos y
                                    0);
    disp.wins[CPU] = create_Module( sys.CPU.getInfo_core().size() / 2 + 2,
                                    COLS,
                                    disp.wins[INFO].height,
                                    0);
    disp.wins[RAM] = create_Module(  5,
                                    COLS,
                                    disp.wins[INFO].height + disp.wins[CPU].height,
                                    0);
    disp.wins[NET] = create_Module(  5,
                                    COLS,
                                    disp.wins[INFO].height + disp.wins[CPU].height + disp.wins[RAM].height,
                                    0);
    disp.wins[SET] = create_Module(  5,
                                    COLS / 2,
                                    LINES - 7,
                                    0);
}
