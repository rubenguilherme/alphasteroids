#include <game_object.hpp>

glm::vec3 GameObject::getPos() {
	return position;
}

int GameObject::checkCollisionWithSphere() {
	if (position.x >= 500 || position.x <= -500) return 1;
	if (position.y >= 500 || position.y <= -500) return 1;
	if (position.z >= 500 || position.z <= -500) return 1;
	return 0;
}

