#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <ctime>
#include "Interfaccia.hpp"
#include "Menu.hpp"
#include "Game.hpp"
using namespace std;

int main()
{
    initscr();
    cbreak();

    Menu start(0, 0);
    start.CreateW();
    if (start.mostraMenu() == "Start")
    {
        Game round(0, 0);
        round.CreateW();
        round.inserisci_nome();
        round.Game_ON();
    }
    endwin();
    return 0;
}