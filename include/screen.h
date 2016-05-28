#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual int run(sf::RenderWindow &app) = 0;
};


#endif // __SCREEN_H__
