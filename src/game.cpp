#include "game.h"
#include "player.h"


int Game::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

    sf::Texture ballTexture;
    ballTexture.loadFromFile("assets/m.png");
    Player ball(ballTexture);
    sf::Clock timer;
    sf::Time elapsed;

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

        elapsed = timer.restart();
        ball.update(elapsed.asSeconds());
        app.draw(ball.sprite());

        // ...
        app.display();
    }

    return -1;
}
