#include <curses.h>
#include <ctime>
#include <string>

void gameLoop()
{
    initscr();
    cbreak();
    noecho();
    int x, y;
    getmaxyx(stdscr, y, x);
    box(stdscr, 0, 0);
    for (int i = 1; i < x - 1; i++)
    {
        mvwaddch(stdscr, y - 10, i, '#');
        mvwaddch(stdscr, y - 4, i, '#');
    }
    for (int i = 1; i < x - 2; i++)
    {
        mvwaddch(stdscr, y - 6, i, '#');
    }
    chtype ch = wgetch(stdscr);

    if (ch == 'l')
    {
        for (int i = 1; i < y - 1; i++)
        {
            int fill = 0;
            for (int t = 1; t < x - 1; t++)
            {
                if (mvwinch(stdscr, i, t) == '#')
                {
                    fill++;
                }
            }
            if (fill == (x - 2))
            {
                for (int s = 1; s < x - 1; s++)
                {
                    mvwaddch(stdscr, i, s, ' ');
                }
                refresh();
            }
        }
    }
    // mvwprintw(stdscr, 2, 2, "%d", x);
    getch();
    endwin();
}

int main()
{
    gameLoop();
    return 0;
}
