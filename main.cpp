#include <SFML/Graphics.hpp>
#include "player.h"


int main(int argc, char const *argv[]) {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Maze");

    sf::Texture ballTexture;
    ballTexture.loadFromFile("assets/m.png");
    Player ball(ballTexture);

    sf::Clock timer;
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::White);

// TODO: main menu, level loading/switching
        sf::Time elapsed = timer.restart();
        ball.update(elapsed.asSeconds());

// TODO: check ball for collision

        window.draw(ball.sprite());

        window.display();
    }
    return 0;
}
