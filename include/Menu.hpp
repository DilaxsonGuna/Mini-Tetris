#ifndef Menu_HPP
#define Menu_HPP
#include "Interfaccia.hpp"
#include <string>

class Menu : public Interfaccia
{
private:
    char nickname[50];

public:
    void inserisci_nome();
    Menu(int a, int b);
    string mostraMenu();
};
#endif