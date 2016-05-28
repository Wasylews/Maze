#include <vector>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "screen.h"
#include "mainmenu.h"
#include "game.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Maze");

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
