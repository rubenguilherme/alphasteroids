#version 330 core

// Input vertex data and color data
layout(location = 0) in vec3 vertexPosition; 
layout(location = 1) in vec3 vertexColor;

uniform mat4 mvp;
uniform mat4 trans;

// Output fragment data
out vec3 fragmentColor;

void main() {
	gl_Position = mvp * vec4(vertexPosition, 1.0);

	// the vertex shader just passes the color to fragment shader
	fragmentColor = vertexColor; 
}