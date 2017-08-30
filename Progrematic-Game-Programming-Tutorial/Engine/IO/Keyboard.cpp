#include "Keyboard.h"

bool Keyboard::keys_held[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keys_down[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keys_up[GLFW_KEY_LAST] = { 0 };

void Keyboard::keyboard_button_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key < 0)
        return;

    bool isPressed = action != GLFW_RELEASE;

    // If there is a disparity between stored values and 
    // actual key state update stored values
    if (isPressed != keys_held[key]) { // xor
        keys_down[key] = !isPressed;
        keys_up[key] = isPressed;
        keys_held[key] = isPressed;
    }
}

bool Keyboard::isKeyDown(int button) {
    bool down = keys_down[button];
    keys_down[button] = false;
    return down;
}

bool Keyboard::isKeyUp(int button) {
    bool up = keys_up[button];
    keys_up[button] = false;
    return up;
}

bool Keyboard::isKeyHeld(int button) {
    return keys_held[button];
}