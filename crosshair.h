#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include <learnopengl/shader_m.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex array object (VAO)
static GLuint crossVAID;

// Vertex buffer object (crossVBO)
static GLuint crossVB;

// color buffer object (crossCBO)
static GLuint crossCB;

static int bufferFlag = 1;

static void renderCrosshair(Shader& cross);
static void drawCross();

static void renderCrosshair(Shader& cross) {
    cross.use();
    glm::mat4 mvp = glm::ortho(-40.0f, 40.0f, -40.0f, 40.0f);
    cross.setMat4("mvp", mvp);
    if (bufferFlag) {
        glGenVertexArrays(1, &crossVAID);
        glGenBuffers(1, &crossVB);
        glGenBuffers(1, &crossCB);
        bufferFlag = 0;
    }
    glBindVertexArray(crossVAID);

	static const GLfloat g_vertex_buffer_data[] = {
		-2.0f, 0.0f, 0.0f,
		2.0f, 0.0f, 0.0f,
		0.0f, -2.0f, 0.0f,
		0.0f, 2.0f, 0.0f
	};
	static const GLfloat g_color_buffer_data[] = {
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f
	};
		    
	// The following commands will talk about our 'crossVB' buffer
	glBindBuffer(GL_ARRAY_BUFFER, crossVB);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
		
	// Move color data to video memory; specifically to crossCBO called crossCB
	glBindBuffer(GL_ARRAY_BUFFER, crossCB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    drawCross();
}

static void drawCross()
{

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, crossVB);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, crossCB);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );

    glDrawArrays(GL_LINES, 0, 4);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

#endif CROSSHAIR_H