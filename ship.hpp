#ifndef SHIP_H
#define SHIP_H

#include <game_object.hpp>
static float angle;

class Ship : public GameObject {
public:
	Ship(Shader &shader, Camera &camera);
	Ship();
	void render();
	
private:

};

#endif SHIP_H