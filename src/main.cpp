#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <curses.h>
#include <ctime>
#include "Interfaccia.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Tetramini.hpp"
using namespace std;

int main()
{
    initscr();
    cbreak();

    Menu start(0, 0);
    if (start.mostraMenu() == "Start")
    {
        start.inserisci_nome();
        noecho();
        Game round;
        round.Game_ON();
    }
    endwin();
    return 0;
}