#ifndef cube_HPP
#define cube_HPP
#include "Tetramini.hpp"
#define vuoto ' '
class cube : public Tetramini
{
protected:
public:
    cube(int xc, int yc, chtype iconc);
    void drawCube(WINDOW *game);
    void natural_down(WINDOW *game);
    void delete_old(WINDOW *game);
    void move_left(WINDOW *game);
    void move_right(WINDOW *game);
};
#endif