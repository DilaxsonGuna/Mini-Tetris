#ifndef Game_HPP
#define Game_HPP
#include "Interfaccia.hpp"
#include <cstring>
#include <ctime>

class Game : public Interfaccia
{
protected:
    char nickname[50];
    int full_lines = 0;
    int score = 0;
    int minutes = 0;
    int seconds = 0;

public:
    Game(int a, int b);
    void inserisci_nome();
    void Stopwatch();
    void Game_ON();
};
#endif