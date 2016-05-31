#include "mainmenu.h"

MainMenu::MainMenu() {
    font.loadFromFile("assets/sansation.ttf");

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
                        int screen = itemSelected(event.mouseButton.x,
                                                  event.mouseButton.y);
                        if (screen != MainMenu::INVALID_SCREEN) {
                            backgroundMusic.stop();
                            return screen;
                        }
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
            pos.y += 64.f;
            m_items[i].item->setPosition(pos);
            app.draw(*m_items[i].item);
        }

        app.display();
    }

    return -1;
}


void MainMenu::addItem(const sf::String &name, const int screen) {
    MenuItem menuItem;
    menuItem.screen = screen;

    menuItem.item = new sf::Text(name, font);
    menuItem.item->setColor(sf::Color::Red);
    menuItem.item->setOrigin(menuItem.item->getLocalBounds().left / 2.0f,
                             menuItem.item->getLocalBounds().top / 2.0f);

    m_items.push_back(menuItem);
}


int MainMenu::itemSelected(float x, float y) {
    for (int i = 0; i < m_items.size(); ++i) {
        if (m_items[i].item->getGlobalBounds().contains(x, y)) {
            return m_items[i].screen;
        }
    }
    return MainMenu::INVALID_SCREEN;
}


MainMenu::~MainMenu() {
    m_items.clear();
}
