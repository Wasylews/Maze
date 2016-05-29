#include "mainmenu.h"

MainMenu::MainMenu() {
    font.loadFromFile("assets/sansation.ttf");
    item.setFont(font);
    item.setColor(sf::Color::Red);

    backgroundTex.loadFromFile("assets/background.png");
    background.setTexture(backgroundTex);
}


int MainMenu::run(sf::RenderWindow &app) {
    sf::Event event;
    bool running = true;

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
