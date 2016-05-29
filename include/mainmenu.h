#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "screen.h"
#include <SFML/Graphics.hpp>


class MainMenu: public Screen {
    std::vector<sf::String> m_items;
    sf::Font font;
    sf::Text item;
public:
    MainMenu();
    void addItem(const sf::String &name);
    virtual int run(sf::RenderWindow &app);
};


#endif // __MAIN_MENU_H__
