#ifndef Ship_h
#define Ship_h

#include <vector>

class Ship {
public:
    int lenght;
    std::vector<std::pair<int, int>> tails; // Lista pól, które zajmuje statek
    
    Ship(int lenght);
    void AddTail(int x, int y);
};

#endif
