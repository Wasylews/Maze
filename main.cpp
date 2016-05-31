#include <vector>
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "mainmenu.h"
#include "game.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Maze");

    std::vector<Screen *> screens;
    int currentScreen = 0;

    MainMenu menu;
    menu.addItem("Play", 1);
    menu.addItem("Options", 2);
    menu.addItem("Exit", -1);
    screens.push_back(&menu);

    Game game;
    screens.push_back(&game);


    while (currentScreen >= 0) {
        currentScreen = screens[currentScreen]->run(window);
    }

    return 0;
}
