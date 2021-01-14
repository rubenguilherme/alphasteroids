#include <game_object.hpp>

glm::vec3 GameObject::getPos() {
	return position;
}

int GameObject::checkCollisionWithSphere() {
	if(sqrt((position.x) * (position.x) +
		(position.y) * (position.y) +
		(position.z) * (position.z)) >= 495) return 1;
	return 0;
}

