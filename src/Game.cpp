#include "Game.hpp"
#define half_board 5
#define first_line 1
#define basic_block '#'
int change = 0;
list<cube> cubes;
auto it = cubes.begin();

Game::Game()
{
    Board = NULL;
}

void Game::Create_Board()
{
    int altezza, base;
    getmaxyx(stdscr, altezza, base);
    Board = newwin(board_height, board_lenght, (altezza / 2) - 10, (base / 2) - 10);
    box(Board, 0, 0);
    update();
    game_status = false;
}

void Game::addCubo()
{
    cubes.emplace_back(half_board, first_line, basic_block);
    it = prev(cubes.end());
    it->drawCube(Board);
}

void Game::cubeDown()
{
    it->natural_down(Board);
}

void Game::cubeLeft()
{
    it->move_left(Board);
}

void Game::cubeRight()
{
    it->move_right(Board);
}

chtype Game::Get_Input()
{
    return wgetch(Board);
}

bool Game::left_check()
{
    bool check;
    if (it->getX() != 1)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool Game::right_check()
{
    bool check;
    if (it->getX() != 9)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool Game::down_check()
{
    bool check;
    if (it->getY() != 19)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

bool Game::collision()
{
    bool check;
    if (mvwinch(Board, it->getY() + 2, it->getX()) != basic_block && mvwinch(Board, it->getY() + 2, it->getX() + 1) != basic_block)
    {
        check = true;
    }
    else
    {
        check = false;
    }
    return check;
}

void Game::Comandi()
{
    keypad(Board, TRUE);
    chtype input = Get_Input();
    if (input == KEY_LEFT && left_check())
    {
        cubeLeft();
    }
    else if (input == KEY_RIGHT && right_check())
    {
        cubeRight();
    }
    else if (collision() && down_check())
    {
        cubeDown();
    }
}

void Game::changes()
{
    if (change == 0)
    {
        addCubo();
        change++;
    }
}

void Game::update()
{
    wrefresh(Board);
}

bool Game::isOver()
{
    return game_status;
}

void Game::Game_ON()
{
    Create_Board();
    while (!isOver())
    {
        Comandi();
        if (collision() && down_check())
        {
            changes();
        }
        else
        {
            change = 0;
            changes();
        }
        update();
    }

    getch();
}