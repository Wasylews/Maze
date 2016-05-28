#include "screen.h"


void Screen::resizeWindow(sf::RenderWindow &app) {
   sf::Vector2f size = static_cast<sf::Vector2f>(app.getSize());

    // minimal size 800x600
    if (size.x < 800) {
        size.x = 800;
    }
    if (size.y < 600) {
        size.y = 600;
    }

    sf::View view = app.getView();
    view.setCenter(size / 2.0f);
    view.setSize(size);

    app.setSize(static_cast<sf::Vector2<unsigned int> >(size));
    app.setView(view);
}
