#include <iostream>
#include "window.h"

int main() {
	GameWindow window;
	std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLFW " << glfwGetVersionString() << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	

	while(!window.shouldClose()) {
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	
	return 0;
}
