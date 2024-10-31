#include "Interfaccia.hpp"

Interfaccia::Interfaccia(int a, int b)
{
    altezza = a;
    base = b;
}

void Interfaccia::CreateW()
{
    WINDOW *win = newwin(altezza, base, 0, 0);
    refresh();

    box(win, 0, 0);
    wrefresh(win);
}