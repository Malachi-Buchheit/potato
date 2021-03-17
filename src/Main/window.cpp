#include "window.h"

void windowResize(GLFWwindow *window, int width, int height);

bool GameWindow::init() {
	std::cout << "Initializing GLFW... ";
	if(!glfwInit())
		return false;
	std::cout << "Done." << std::endl;

	std::cout << "Creating window... ";
	window = glfwCreateWindow(width, height, "potato", NULL, NULL);
	if(!window)
		return false;
	std::cout << "Done." << std::endl;

	glfwSetWindowSizeCallback(window, windowResize);
	glfwMakeContextCurrent(window);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	std::cout << "Initializing GLEW... ";
	glewExperimental = GL_TRUE;
	if(glewInit())
		return false;
	std::cout << "Done." << std::endl;

	return true;
}

GameWindow::GameWindow() {
	if(!init())
		std::cout << "FAILED!" << std::endl;
	
}

GameWindow::~GameWindow() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GameWindow::update() {
	glfwPollEvents();
	glfwSwapBuffers(window);
}

void GameWindow::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void windowResize(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}
