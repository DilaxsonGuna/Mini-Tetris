#include "Game.hpp"

Game::Game(int a, int b) : Interfaccia(a, b)
{
    strcpy(nickname, "Player 1");
}

void Game::inserisci_nome()
{
    werase(temp);
    mvwprintw(temp, altezza / 2, base / 2, "Inserisci nickname: ");
    wrefresh(temp);

    char input[100] = "";
    int index = 0;

    while (true)
    {
        mvwprintw(temp, altezza / 2, (base / 2) + 20, "%s", input);
        wrefresh(temp);

        int ch = wgetch(temp);

        if (ch == '\n')
        {
            break;
        }
        else if (ch == KEY_BACKSPACE || ch == 127)
        {
            if (index > 0)
            {
                index--;             // Move back in the buffer
                input[index] = '\0'; // Null-terminate the string
            }
        }
        else if (index < sizeof(input) - 1)
        {
            input[index++] = ch; // Store character in buffer
            input[index] = '\0'; // Null-terminate the string
        }
    }

    strcpy(nickname, input);

    werase(temp);
    mvwprintw(temp, 1, 1, "Nickname set to: %s", nickname);
    wrefresh(temp);

    getch();
}