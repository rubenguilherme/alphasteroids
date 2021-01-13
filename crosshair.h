#ifndef CROSSHAIR_H
#define CROSSHAIR_H
#include <learnopengl/shader_m.h>

// Vertex array object (VAO)
GLuint VertexArrayID;

// Vertex buffer object (VBO)
GLuint vertexbuffer;

// color buffer object (CBO)
GLuint colorbuffer;

void render() {

	static const GLfloat g_vertex_buffer_data[] = {
		0.0f, 0.0f, 0.0f,
		20.0f, 0.0f, 0.0f,
		20.0f, 20.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 20.0f, 0.0f,
		20.0f, 20.0f, 0.0f
	};
	static const GLfloat g_color_buffer_data[] = {
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f,
		1.0f,  1.0f,  0.0f
	};
		    
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
		
	// Move color data to video memory; specifically to CBO called colorbuffer
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
}

void draw()
{
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
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
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_LINE, 0, 4); // 3 indices starting at 0 -> 1 triangle


    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

#endif CROSSHAIR_H