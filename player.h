#ifndef player_h
#define player_h

#include <string>
#include "Board.h"

class Player {
public:
    std::string name;
    Board board;
    
    Player(std::string name);
    void setShips(); 
    bool shootToOpponent(int x, int y);
    bool ifAllDestroyed();
};

#endif
