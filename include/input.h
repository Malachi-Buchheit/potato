#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <unordered_map>
#include </usr/include/GL/glew.h>
#include </usr/include/GLFW/glfw3.h>

namespace input {

enum enum_actions {
    START, SELECT,
    A, B, X, Y,
    UP, DOWN, LEFT, RIGHT,
    NUM_ACTIONS
};

struct struct_hotkeys {
    std::unordered_map<int, enum_actions> hotkeys;
    bool actions[NUM_ACTIONS];
};

void init_default_hotkeys();
void on_key_event(GLFWwindow *window, int key, int scancode, int action, int mods);
bool *const get_actions();

};

#endif
