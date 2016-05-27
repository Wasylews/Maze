#include "player.h"


void Player::update(double dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_sprite.move(-dt*dx, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_sprite.move(dt*dx, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_sprite.move(0, -dt*dy);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_sprite.move(0, dt*dy);
    }
}
