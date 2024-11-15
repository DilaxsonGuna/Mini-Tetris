#include "Menu.hpp"

Menu::Menu(int a, int b) : Interfaccia(a, b)
{
}

string Menu::mostraMenu()
{
    string titolo = "Tetris";
    int titleLength = titolo.length();
    int pos_iniziale = (base - titleLength) / 2;
    int altezza_iniziale = altezza / 3;
    mvwprintw(temp, altezza_iniziale, pos_iniziale, titolo.c_str()); // Stampa il titolo

    wrefresh(temp); // Aggiorna la finestra per visualizzare i cambiamenti

    // Selezione multipla
    string choices[3] = {"Start", "Classifica", "Exit"};
    int choice;
    int highlight = 0;

    int pos_iniziale_menu = altezza / 2;

    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == highlight)
                wattron(temp, A_REVERSE);
            mvwprintw(temp, pos_iniziale_menu + i, pos_iniziale, choices[i].c_str());
            wattroff(temp, A_REVERSE);
        }
        choice = wgetch(temp);

        switch (choice)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 3)
                highlight = 2;
            break;
        default:
            break;
        }
        if (choice == 10)
            break;
    }
    delwin(temp);
    return choices[highlight];
}
