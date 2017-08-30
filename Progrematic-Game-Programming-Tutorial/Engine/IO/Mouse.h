#ifndef __PGMT_ENGINE_IO__MOUSE_H__
#define __PGMT_ENGINE_IO__MOUSE_H__

#include <GLFW\glfw3.h>

class Mouse {
public:
    static void mouse_pos_callback(GLFWwindow *window, double x, double y);
    static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);

    static double getMouseX();
    static double getMouseY();

    static bool isButtonDown(int button);
    static bool isButtonUp(int button);
    static bool isButtonHeld(int button);

private:
    static double x;
    static double y;

    // while down
    static bool buttons_held[];
    // just press
    static bool buttons_down[];
    // just release
    static bool buttons_up[];
};

#endif