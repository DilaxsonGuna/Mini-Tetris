#include <curses.h>
#include <ctime>
#include <string>

void gameLoop()
{
    initscr();
    cbreak();
    noecho();

    // Inizializza tempo di inizio
    time_t startTime = time(NULL);

    int score = 0; // Supponiamo che ci sia anche un punteggio

    while (true)
    {
        // Calcola il tempo trascorso
        time_t currentTime = time(NULL);
        int elapsedSeconds = difftime(currentTime, startTime);

        // Calcola minuti e secondi
        int minutes = elapsedSeconds / 60;
        int seconds = elapsedSeconds % 60;

        // Mostra il punteggio e il tempo
        mvprintw(1, 1, "FULL LINES: %d", score);
        mvprintw(2, 1, "TIME: %02d:%02d", minutes, seconds); // Formato MM:SS

        refresh();

        // Logica di gioco, input, ecc.
        int ch = getch();
        if (ch == 'q')
            break; // Esce dal ciclo di gioco con 'q'

        // Aggiorna il contenuto della finestra (se necessario)
        napms(500); // Ritarda di 500 ms per vedere l'aggiornamento
    }

    endwin();
}

int main()
{
    gameLoop();
    return 0;
}
