#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "player.h"


class Level {
    char **pf;
    int m, n, bx, by;

    static const char OBSTACLE = '#';
    static const char PASS = '=';
    static const char BEG = 'b';
    static const char END = 'e';
public:
    Level(const std::string &filename);
    void update(const sf::RenderWindow &app);
    bool isCollide(Player &p);
    ~Level();
};

#endif // __LEVEL_H__
