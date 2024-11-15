#ifndef Menu_HPP
#define Menu_HPP
#include "Interfaccia.hpp"
#include <string>

class Menu : public Interfaccia
{
private:
public:
    Menu(int a, int b);
    string mostraMenu();
};
#endif