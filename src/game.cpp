#include "game.h"

int Game::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

    while (running) {
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return -1;
            }
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        return 0;
                        break;
                    default:
                        break;
                }
            }
        }
        app.clear(sf::Color::Red);
        // ...
        app.display();
    }

    return -1;
}
