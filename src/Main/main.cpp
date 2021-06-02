#include <iostream>
#include "window.h"
#include "math.h"
#include "shader.h"
#include "simple_2d_renderer.h"
#include "batch_2d_renderer.h"
#include "static_sprite.h"
#include "sprite.h"
#include "renderable_2d.h"

#include <time.h>


//static u_int32_t ticks = 0;

int main() {
	GameWindow window;

	std::cout << "OpenGL " << glGetString(GL_VERSION) << "\n"
			  << "GLFW " << glfwGetVersionString() << "\n"
			  << "GLEW " << GLEW_VERSION_MAJOR << "." << GLEW_VERSION_MINOR << std::endl;

	input::init_default_hotkeys();

	math::mat4 ortho = math::mat4::orthographic(0, 16, 0, 9, -1, 1);

	graphics::Shader shader("./res/shaders/basic.vert", "./res/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("vw_matrix", math::mat4::translation(math::vec3(10, 5, 0)));
	//shader.setUniformMat4("ml_matrix", math::mat4::rotation(45, math::vec3(0, 0, 1)));
	shader.setUniform4f("light_color", math::vec4(1,1,1,1));
	math::vec2 light_pos;
	float light_brightness = 4;
	shader.setUniform2f("light_pos", light_pos);
	shader.setUniform1f("light_brightness", light_brightness);

	std::vector<graphics::Renderable2D*> sprites;
	srand(time(NULL));
	float scale = 3;
	for(float y = 0; y < 9*scale; y++)
		for(float x = 0; x < 16*scale; x++)
			sprites.push_back(new graphics::Sprite(x/scale, y/scale, 0.9f/scale, 0.9f/scale, math::vec4(rand()%1000/1000.0f, rand()%1000/1000.0f, rand()%1000/1000.0f, 1)));
	//graphics::Sprite sprite(2, 3, 2, 2, math::vec4(1, 1, 1, 1));
	//graphics::Renderable2D sprite1(math::vec3(1, 2, 0), math::vec2(1, 2), math::vec4(1, 0, 1, 1), shader);
	//graphics::Simple2DRenderer renderer;
	graphics::Batch2DRenderer renderer;
	
	clock_t t;
	float min = -1, max = -1, val;
	long count = 0;
	long double sum = 0;
	while(!window.shouldClose()) {
		t = clock(); count++;


		window.clear();
		#define SPEED 0.05f
		if(input::get_actions()[input::RIGHT])
			light_pos += math::vec2(SPEED,0);
		if(input::get_actions()[input::LEFT])
			light_pos += math::vec2(-SPEED,0);
		if(input::get_actions()[input::UP])
			light_pos += math::vec2(0,-SPEED);
		if(input::get_actions()[input::DOWN])
			light_pos += math::vec2(0,SPEED);
		if(input::get_actions()[input::A])
			light_brightness += SPEED;
		if(input::get_actions()[input::B])
			light_brightness -= SPEED;
		shader.setUniform2f("light_pos", light_pos);
		shader.setUniform1f("light_brightness", light_brightness);
		renderer.begin();
		for(auto sprite : sprites)
			renderer.submit(sprite);
		renderer.end();
		renderer.flush();
		window.update();


		t = clock() - t;
		val = CLOCKS_PER_SEC/(float)t;
		sum += val;
		if(min == -1 || val < min)
			min = val;
		if(max == -1 || val > max)
			max = val;
		std::cout << "FPS: " << val << std::endl;
	}

	std::cout << "\nMAX FPS: " << max << "\n"
			  << "MIN FPS: " << min << "\n" 
			  << "AVG FPS: " << sum/count
			  << std::endl;
	
	return 0;
}
