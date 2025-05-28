// src/main.cpp
#include <ncurses.h>

int main() {
    initscr();
    printw("LvlUp-CLI is running!\nPress any key to exit...");
    refresh();
    getch();
    endwin();
    return 0;
}
