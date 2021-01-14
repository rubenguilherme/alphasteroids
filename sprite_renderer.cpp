#include <sprite_renderer.hpp>

SpriteRenderer::SpriteRenderer(Shader & shader, Camera & camera, const char *path)
{
	this->shader = &shader;
    this->camera = &camera;
	this->initModel(path);
}

SpriteRenderer::SpriteRenderer()
{
    
}

void SpriteRenderer::DrawSprite(glm::vec3 position, glm::vec3 scale, GLfloat Yaw, GLfloat Pitch, GLfloat Roll) {
    // don't forget to enable shader before setting uniforms
    shader->use();
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    float p = Pitch;
    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 1000.0f);
    glm::mat4 view = camera->GetViewMatrix();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    // render the loaded model
    glm::mat4 modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, position);

    //TO DO : Change it only for the ship
    if (Yaw != 0.0f) {
        modelMat = glm::translate(modelMat, glm::vec3(0.0f, 1.0f, 0.0f)); // we rotate to the camera position so it rotates like the camera
        modelMat = glm::rotate(modelMat, Yaw, glm::vec3(0.0f, 1.0f, 0.0f));
        modelMat = glm::rotate(modelMat, Pitch, glm::vec3(1.0f, 0.0f, 0.0f));
        modelMat = glm::translate(modelMat, glm::vec3(0.0f, -1.0f, 0.0f)); // after rotating we go back to the place we were
    }
    
    
    //modelMat = glm::rotate(modelMat,Roll, glm::vec3(0.0f, 0.0f, 1.0f));
    modelMat = glm::scale(modelMat, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    shader->setMat4("model", modelMat);
    //std::cout << &model << std::endl;
    model.Draw(*shader);
}

void SpriteRenderer::initModel(const char* path)
{
	model = Model(path);
}