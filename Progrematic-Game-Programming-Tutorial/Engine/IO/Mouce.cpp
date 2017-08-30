#include "Mouse.h"

double Mouse::x = -1;
double Mouse::y = -1;

bool Mouse::buttons_held[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttons_down[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttons_up[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::mouse_pos_callback(GLFWwindow *window, double _x, double _y) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    x = _x;
    y = height - _y;
}

void Mouse::mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
    if (button < 0)
        return;

    bool isPressed = action != GLFW_RELEASE;

    // If there is a disparity between stored values and 
    // actual button state update stored values
    if (isPressed != buttons_held[button]) { // xor
        buttons_down[button] = !isPressed;
        buttons_up[button] = isPressed;
        buttons_held[button] = isPressed;
    }

}

double Mouse::getMouseX() {
    return x;
}

double Mouse::getMouseY() {
    return y;
}

bool Mouse::isButtonDown(int button) {
    bool down = buttons_down[button];
    buttons_down[button] = false;
    return down;
}

bool Mouse::isButtonUp(int button) {
    bool up = buttons_up[button];
    buttons_up[button] = false;
    return up;
}

bool Mouse::isButtonHeld(int button) {
    return buttons_held[button];
}