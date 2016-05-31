#include "level.h"

Level::Level(const std::string &filename) {
    std::ifstream fin(filename.c_str());

    if(fin.is_open()) {
        fin >> m >> n;
        pf = new char *[n];

        for(int i = 0; i < n; i++) {
            pf[i] = new char[m];
        }

        for(int i = 0; i < n; i++) {
            fin >> pf[i];
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(pf[i][j] == Level::BEG) {
                    bx = j;
                    by = i;
                } else {
                    pf = NULL;
                    n = bx = by = 0;
                }
            }
        }
}


void Level::update(const sf::RenderWindow &app) {

}

bool Level::isCollide(Player &p) {
    int x = p.x();
    int y = p.y();
    Direction dir = p.way();

    switch (dir) {
        case UP:
            --y;
            break;
        case DOWN:
            ++y;
            break;
        case LEFT:
            --x;
            break;
        default:
            ++x;
    }

    return (x >= 0 && x < m && y >= 0 && y < n && pf[y][x] != Level::OBSTACLE);
}
