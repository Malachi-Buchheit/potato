#include "window.h"

void window_resize_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

bool GameWindow::init() {
	std::cout << "Initializing GLFW... ";
	if(!glfwInit()) return false;
	std::cout << "Done." << std::endl;

	std::cout << "Creating window... ";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(width, height, "potato", NULL, NULL);
	if(!window) return false;
	glfwSetWindowSizeCallback(window, window_resize_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	std::cout << "Done." << std::endl;

	std::cout << "Initializing GLEW... ";
	glewExperimental = GL_TRUE;
	if(glewInit()) return false;
	std::cout << "Done." << std::endl;

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	return true;
}

GameWindow::GameWindow() {
	if(!init()) std::cout << "FAILED!" << std::endl;
}

GameWindow::~GameWindow() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GameWindow::update() {
	GLenum error = glGetError();
	if(error != GL_NO_ERROR)
		std::cout << "ERROR: " << gluErrorString(error) << std::endl;
	glfwPollEvents();
	glfwSwapBuffers(window);
}

void GameWindow::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void window_resize_callback(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	input::on_key_event(window, key, scancode, action, mods);
}
