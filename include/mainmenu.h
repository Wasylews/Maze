#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>


struct MenuItem {
    int screen;
    sf::Text *item;
};


class MainMenu: public Screen {
    std::vector<MenuItem> m_items;
    sf::Font font;

    sf::Texture backgroundTex;
    sf::Sprite background;

    sf::Music backgroundMusic;

    static const int INVALID_SCREEN = 65536;

    int itemSelected(float x, float y);
public:
    MainMenu();
    void addItem(const sf::String &name, const int screen);
    virtual int run(sf::RenderWindow &app);
    ~MainMenu();
};


#endif // __MAIN_MENU_H__
