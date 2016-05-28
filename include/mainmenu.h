#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "screen.h"
#include <SFML/Graphics.hpp>

class MainMenu: public Screen{
public:
    MainMenu() {};
    virtual int run(sf::RenderWindow &app);
};


#endif // __MAIN_MENU_H__
