/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** cpu
*/

#include "monitor.h"
#include <array>

void draw_core(int max, int current, core_t elems, MonitorDisplay &disp)
{
    float use = std::stof(elems.frequency) * 100 / std::stof(elems.frequency_max);
    if (use > 100) use = 100;
    int obj = ((float)COLS / 2 - 13) * (use / 100);
    int pos;
    int score = current;
    bool secondPart = !(current < max / 2 + 1);
    if (!secondPart) {
        pos = 2;
    } else {
        pos = COLS / 2 + 1;
        current -= max / 2;
    }
    mvwprintw(disp.wins[CPU].win, current, pos, "%3d", score);
    pos += 4;
    mvwaddch(disp.wins[CPU].win, current, pos++, '[');
    for (int i = 0; i < obj; i++) {
        mvwaddch(disp.wins[CPU].win, current, pos++, ACS_CKBOARD);
    }
    mvwprintw(disp.wins[CPU].win, current, secondPart ? (COLS / 2 - 6) : (COLS - 8), "%3.f%]", use);
}

void draw_cpu(MonitorDisplay &disp, const System &sys)
{
    int core_nb = sys.CPU.getInfo_core().size();
    std::string model = sys.CPU.getModel().empty() ? "unknown model" : sys.CPU.getModel();

    wclear(disp.wins[CPU].win);
    box(disp.wins[CPU].win, 0, 0);
    wprintw(disp.wins[CPU].win, "CPU : %s", model.data());
    for (int i = 0; i < core_nb; i++) {
        draw_core(core_nb, i + 1, sys.CPU.getInfo_core()[i], disp);
    }
}
