#include "mainmenu.h"

int MainMenu::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

    while (running) {
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Return:
                        return 1;
                        break;
                    default:
                        break;
                }
            }
        }
        app.clear(sf::Color::White);
        // ...
        app.display();
    }

    return -1;
}
