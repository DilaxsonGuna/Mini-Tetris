#include <iostream>
#include <cstdlib>
#include <curses.h>
#include "Interfaccia.hpp"
#include "Menu.hpp"
using namespace std;

int main()
{
    initscr();
    noecho();
    cbreak();

    Menu start(0, 0);
    start.CreateW();
    start.mostraMenu();

    endwin();
    return 0;
}