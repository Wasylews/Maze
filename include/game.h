#ifndef __GAME_H__
#define __GAME_H__

#include "screen.h"
#include <SFML/Graphics.hpp>

class Game: public Screen {
public:
    Game() {};
    virtual int run(sf::RenderWindow &app);

};


#endif // __GAME_H__
