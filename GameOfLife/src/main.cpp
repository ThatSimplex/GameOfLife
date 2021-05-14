#include "graphics/Shader.h"
#include "graphics/window/Window.h"
#include "graphics/buffers/Buffer.h"
#include "graphics/buffers/VertexArray.h"

#include <iostream>
#include <glad/glad.h>

int main() {
		float vertices[] = {
		 0.0f,   0.5f,  0.0f,
		-0.5f,  -0.5f,  0.0f,
		 0.5f,  -0.5f,  0.0f
	};

	GoL::Window window(800, 600, "Test");

	gladLoadGL();

	GoL::Shader shader("res/shaders/TestVertexShader.vert", "res/shaders/TestFragmentShader.frag");

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	GLuint VBO;
	GLuint VAO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	while (!window.Closed()) {
		window.Clear();

		shader.Use();

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		int vertexColorLocation = glGetUniformLocation(shader.ID, "ourColor");
		glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		window.Update();
	}

	return 0;
}