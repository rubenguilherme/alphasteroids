//
//  text_renderer.hpp
//  cg_project
//
//  Created by Paulo Duarte on 14/01/2021.
//

#ifndef text_renderer_hpp
#define text_renderer_hpp

#include <game_object.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class TextRenderer {
public:
    TextRenderer();
    void render(Shader &shader, std::string text, float x, float y, float scale, glm::vec3 color);
    void setupShader(Shader &shader, int SCR_WIDTH, int SCR_HEIGHT);
    void loadFont();
protected:
    glm::vec3 position;
    // Holds all state information relevant to a character as loaded using FreeType
    struct Character {
        unsigned int TextureID; // ID handle of the glyph texture
        glm::ivec2   Size;      // Size of glyph
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Horizontal offset to advance to next glyph
    };
    std::map<GLchar, Character> Characters;
    unsigned int VAO, VBO;
};

#endif /* text_renderer_hpp */
