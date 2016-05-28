#include <vector>
#include <SFML/Graphics.hpp>
#include "screen.h"
#include "mainmenu.h"
#include "game.h"


int main(int argc, char const *argv[]) {
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    sf::RenderWindow window(modes[0], "Maze");

    std::vector<Screen *> screens;
    int currentScreen = 0;

    MainMenu menu;
    screens.push_back(&menu);

    Game game;
    screens.push_back(&game);


    while (currentScreen >= 0) {
        currentScreen = screens[currentScreen]->run(window);
    }

    return 0;
}
