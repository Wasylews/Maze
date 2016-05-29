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
            switch (event.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::Resized:
                    resizeWindow(app);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        return 0;
                default:
                // error, unknown event type
                    break;
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
