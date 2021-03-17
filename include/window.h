#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include </usr/include/GL/glew.h>
#include </usr/include/GLFW/glfw3.h>

class GameWindow {
	private:
	GLFWwindow *window;
	int width = 640, height = 480;
	
	public:
	GameWindow();
	virtual ~GameWindow();
	void update();
	void clear();
	void close() {glfwSetWindowShouldClose(window, true);};
	bool shouldClose() {return glfwWindowShouldClose(window);}
	
	private:
	bool init();
};

#endif
