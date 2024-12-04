#ifndef Tetramini_HPP
#define Tetramini_HPP
#include <curses.h>

class Tetramini
{
protected:
    int x, y;
    chtype icon;

public:
    Tetramini(int x = 0, int y = 0, chtype icon = ' ');
    int getX();
    int getY();
    chtype getIcon();
};

#endif