#include "Tetramini.hpp"

Tetramini::Tetramini(int x, int y, chtype icon)
{
    this->x = x;
    this->y = y;
    this->icon = icon;
}

int Tetramini::getX()
{
    return x;
}

int Tetramini::getY()
{
    return y;
}

chtype Tetramini::getIcon()
{
    return icon;
}
