#ifndef Interfaccia_HPP
#define Interfaccia_HPP
#include <curses.h>

class Interfaccia
{
private:
    int altezza;
    int base;

public:
    Interfaccia(int a = 0, int b = 0);
    void CreateW();
};

#endif