#include "Interfaccia.hpp"

Interfaccia::Interfaccia(int a, int b)
{
    getmaxyx(stdscr, a, b);
    altezza = a;
    base = b;
    temp = newwin(altezza, base, 0, 0);
    refresh();
}

void Interfaccia::CreateW()
{
    box(temp, 0, 0);
    wrefresh(temp);

    keypad(temp, true);
}