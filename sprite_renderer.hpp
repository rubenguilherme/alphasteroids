#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <learnopengl/shader_m.h>
#include <learnopengl/camera.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include <learnopengl/model.h>

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &shader, Camera & camera, const char *path);
	SpriteRenderer();

	void DrawSprite(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(0.0f, 0.0f, 0.0f), GLfloat Yaw =  glm::radians(0.0f), GLfloat Pitch = glm::radians(0.0f), GLfloat = glm::radians(0.0f));

private:
	Shader * shader;
	Camera * camera;
	Model model;
	void initModel(const char* path);
};

#endif SPRITE_RENDERER_H