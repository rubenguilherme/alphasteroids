#include <asteroid.hpp>

Asteroid::Asteroid(Shader &shader, Camera &camera) {
	this->shader = &shader;
	this->camera = &camera;
	position = glm::vec3(5.0f,3.0f,0.0f);
	spriterenderer = SpriteRenderer(*(this->shader), *(this->camera), "/Users/pauloduarte/Documents/cg_project/cg_project/objects/asteroid4.obj");
}

Asteroid::Asteroid() {}

void Asteroid::render() {
	spriterenderer.DrawSprite(position);
}
