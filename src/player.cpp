#include "player.h"


void Player::update(double dt) {
    // TODO: calculate step
    m_sprite.move(dt*10, dt*10);
}
