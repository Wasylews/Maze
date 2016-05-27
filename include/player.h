#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>


class Player {
    sf::Sprite m_sprite;
public:
    Player(sf::Texture &tex): m_sprite(tex) {};

    void update(double dt);

    const sf::Sprite &sprite() {
        return m_sprite;
    };
};

#endif // __PLAYER_H__
