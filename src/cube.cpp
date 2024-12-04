#include "cube.hpp"

cube::cube(int xc, int yc, chtype iconc)
{
    this->x = xc;
    this->y = yc;
    this->icon = iconc;
}

void cube::drawCube(WINDOW *game)
{
    mvwaddch(game, y, x, icon);
    mvwaddch(game, y, x + 1, icon);
    mvwaddch(game, y + 1, x, icon);
    mvwaddch(game, y + 1, x + 1, icon);
}

void cube::delete_old(WINDOW *game)
{
    mvwaddch(game, y, x, vuoto);
    mvwaddch(game, y, x + 1, vuoto);
    mvwaddch(game, y + 1, x, vuoto);
    mvwaddch(game, y + 1, x + 1, vuoto);
}

void cube::natural_down(WINDOW *game)
{
    delete_old(game);
    y = y + 1;
    drawCube(game);
}

void cube::move_left(WINDOW *game)
{
    delete_old(game);
    x = x - 1;
    drawCube(game);
}

void cube::move_right(WINDOW *game)
{
    delete_old(game);
    x = x + 1;
    drawCube(game);
}