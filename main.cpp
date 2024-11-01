#include <iostream>
#include <curses.h>
#include "Interfaccia.hpp"
using namespace std;

int main()
{
    initscr();
    Interfaccia menu;
    menu.CreateW();
    int c = getch();
    endwin();
    return 0;
}