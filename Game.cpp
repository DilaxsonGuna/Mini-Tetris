#include "Game.hpp"

Game::Game(int a, int b) : Interfaccia(a, b)
{
    strcpy(nickname, "Player 1");
}

void Game::inserisci_nome()
{

    mvwprintw(temp, altezza / 2, base / 2, "Inserisci nickname: ");
    wrefresh(temp);

    mvwprintw(temp, altezza / 2, base / 2 + 20, "");

    wgetnstr(temp, nickname, sizeof(nickname) - 1);
    werase(temp);
    wrefresh(temp);
}

void Game::Game_ON()
{
    box(temp, 0, 0);
    wrefresh(temp);
    mvprintw(1, 1, nickname);
    mvprintw(2, 1, "FULL LINES: %d", score);
    getch();
}