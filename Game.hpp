#ifndef Game_HPP
#define Game_HPP
#include "Interfaccia.hpp"
#include <cstring>

class Game : public Interfaccia
{
protected:
    char nickname[50];

public:
    Game(int a, int b);
    void inserisci_nome();
};
#endif