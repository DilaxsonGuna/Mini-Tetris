#ifndef Interfaccia_HPP
#define Interfaccia_HPP
#include <curses.h>
#include <cstdlib>
using namespace std;

class Interfaccia
{
protected:
    int altezza;
    int base;
    WINDOW *temp;

public:
    Interfaccia(int a = 0, int b = 0);
    void CreateW();
};

#endif