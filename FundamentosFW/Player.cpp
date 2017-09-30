#include "Player.h"



Player::Player()
{
}


void Player::init(float speed, glm::vec2 position) {
	_speed = speed;
	_position = position;
	color.set(0, 0, 185, 255);
}

void Player::update() {

}


Player::~Player()
{
}
