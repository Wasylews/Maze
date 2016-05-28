#include "mainmenu.h"

int MainMenu::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

    sf::Font font;
    font.loadFromFile("assets/sansation.ttf");

    sf::Text playGame("Play", font);
    playGame.setCharacterSize(24);
    playGame.setColor(sf::Color::Red);

    // sf::FloatRect textRect = playGame.getLocalBounds();
    // playGame.setOrigin(textRect.left + textRect.width/2.0f,
    //                textRect.top  + textRect.height/2.0f);
    // playGame.setPosition(sf::Vector2f(SCRWIDTH/2.0f,SCRHEIGHT/2.0f));

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
                    if (event.key.code == sf::Keyboard::Return)
                        return 1;
                default:
                // error, unknown event type
                    break;
            }
        }
        app.clear(sf::Color::White);

        app.draw(playGame);

        app.display();
    }

    return -1;
}
