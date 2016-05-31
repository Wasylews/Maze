#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class Player {
    sf::Sprite m_sprite;
    int m_x, m_y;
    Direction m_way;

    static const double dx = 50;
    static const double dy = 50;
public:
    Player(sf::Texture &tex): m_sprite(tex) {};

    const int x();
    const int y();
    const Direction way();

    void update(double dt);

    const sf::Sprite &sprite() {
        return m_sprite;
    };
};

#endif // __PLAYER_H__
