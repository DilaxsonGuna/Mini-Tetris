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

void Game::Stopwatch()
{
    while (1)
    {
        seconds++;
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
        }
        napms(1000);
    }
}

void Game::Game_ON()
{
    box(temp, 0, 0);
    wrefresh(temp);
    mvprintw(1, 1, nickname);
    mvprintw(2, 1, "FULL LINES: %d", full_lines);
    mvprintw(3, 1, "Score: %d", score);
    mvprintw(4, 1, "Time: %d", minutes, ":%d", seconds);
    getch();
}