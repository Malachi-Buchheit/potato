#include "input.h"

using namespace input;

static struct_hotkeys hotkeys;

void input::init_default_hotkeys() {
    hotkeys.hotkeys[GLFW_KEY_ESCAPE] = START;
    hotkeys.hotkeys[GLFW_KEY_TAB] = SELECT;
    hotkeys.hotkeys[GLFW_KEY_SPACE] = A;
    hotkeys.hotkeys[GLFW_KEY_LEFT_SHIFT] = B;
    hotkeys.hotkeys[GLFW_KEY_E] = X;
    hotkeys.hotkeys[GLFW_KEY_R] = Y;
    hotkeys.hotkeys[GLFW_KEY_W] = UP;
    hotkeys.hotkeys[GLFW_KEY_S] = DOWN;
    hotkeys.hotkeys[GLFW_KEY_A] = LEFT;
    hotkeys.hotkeys[GLFW_KEY_D] = RIGHT;
}

void input::on_key_event(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if(hotkeys.hotkeys.find(key) != hotkeys.hotkeys.end())
        hotkeys.actions[hotkeys.hotkeys.at(key)] = action != GLFW_RELEASE;
}

bool *const input::get_actions() {
    return hotkeys.actions;
}
