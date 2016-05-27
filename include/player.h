#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Player {
    sf::Sprite m_sprite;
    static const double dx = 50;
    static const double dy = 50;
public:
    Player(sf::Texture &tex): m_sprite(tex) {};

    void update(double dt);

    const sf::Sprite &sprite() {
        return m_sprite;
    };
};

#endif // __PLAYER_H__
