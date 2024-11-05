#include <iostream>
#include <cstdlib>
#include <curses.h>
#include "Interfaccia.hpp"
#include "Menu.hpp"
#include "Game.hpp"
using namespace std;

int main()
{
    initscr();
    noecho();
    cbreak();

    Menu start(0, 0);
    start.CreateW();
    if (start.mostraMenu() == "Start")
    {
        Game round(0, 0);
        round.CreateW();
        round.inserisci_nome();
    }
    endwin();
    return 0;
}