#ifndef Game_HPP
#define Game_HPP
#include <cstring>
#include <ctime>
#include <list>
#include <curses.h>
#include <cstdlib>
#include "Tetramini.hpp"
#include "cube.hpp"
#define board_lenght 12
#define board_height 22
using namespace std;

class Game
{
protected:
    int full_lines = 0;
    int score = 0;
    int minutes = 0;
    int seconds = 0;
    WINDOW *Board = NULL;
    bool game_status;

public:
    Game();
    void Create_Board();
    void addCubo();
    void cubeDown();
    void cubeLeft();
    void cubeRight();
    chtype Get_Input();
    bool left_check();
    bool right_check();
    bool down_check();
    bool collision();
    void linedelete(int y);
    void linecheck();
    void Comandi();
    void changes();
    void update();
    bool isOver();
    void Stopwatch();
    void Game_ON();
};
#endif