/*
** EPITECH PROJECT, 2021
** rush3
** File description:
** sys
*/

#include "monitor.h"

void draw_sys(MonitorDisplay &disp, const System &sys)
{
    //fetched data
    std::string time = sys.time.getTime();
    std::string host = sys.user.getHostname();
    std::string user = sys.user.getUsername();
    std::string kernel = sys._kernel.get_kernel_version();
    std::string os = sys._kernel.get_operating_system();

    //indexes
    uint y = 2;
    uint x = 1;

    wclear(disp.wins[INFO].win);
    box(disp.wins[INFO].win, 0, 0);
    wprintw(disp.wins[INFO].win, "System Information");
    mvwprintw(disp.wins[INFO].win, y++, x, "Time:       %s", time.empty() ? "unknown" : time.data());
    mvwprintw(disp.wins[INFO].win, y++, x, "Hostname:   %s", host.empty() ? "unknown" : host.data());
    mvwprintw(disp.wins[INFO].win, y++, x, "Username:   %s", user.empty() ? "unknown" : user.data());
    x += COLS / 2;
    y = 2;
    mvwprintw(disp.wins[INFO].win, y++, x, "Operating system:   %s", !os.empty() ? os.data() : "unknown");
    mvwprintw(disp.wins[INFO].win, y++, x, "Kernel version:     %s", !kernel.empty() ? kernel.data() : "unknown");
}
