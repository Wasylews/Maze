#include "mainmenu.h"

MainMenu::MainMenu() {
    font.loadFromFile("assets/sansation.ttf");
    item.setFont(font);
    item.setColor(sf::Color::Red);

    backgroundTex.loadFromFile("assets/background.jpg");
    background.setTexture(backgroundTex);

    backgroundMusic.openFromFile("assets/menu.ogg");
    backgroundMusic.setLoop(true);
}


int MainMenu::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

    backgroundMusic.play();

    while (running) {
        while (app.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::Resized:
                    resizeWindow(app);
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        backgroundMusic.stop();
                        // TODO: check mouse clicks on text
                        return 1;
                    }
                    break;
                default:
                // error, unknown event type
                    break;
            }
        }
        app.clear();

        sf::Vector2f pos = app.getView().getSize();
        background.setTextureRect(sf::IntRect(0, 0, pos.x, pos.y));

        app.draw(background);

        pos.x /= 2.f;
        pos.y /= 4.f;

        for (int i = 0; i < m_items.size(); ++i) {
            item.setString(m_items[i]);
            item.setOrigin(item.getLocalBounds().left/2.0f,
                           item.getLocalBounds().top/2.0f);
            pos.y += 64.f;
            item.setPosition(pos);
            app.draw(item);
        }

        app.display();
    }

    return -1;
}


void MainMenu::addItem(const sf::String &name) {
    m_items.push_back(name);
}
