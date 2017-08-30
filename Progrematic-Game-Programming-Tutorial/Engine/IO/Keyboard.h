#ifndef __PGMT_ENGINE_IO__KEYBOARD_H__
#define __PGMT_ENGINE_IO__KEYBOARD_H__

#include <GLFW\glfw3.h>

class Keyboard {
public:
    static void keyboard_button_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
    
    static bool isKeyDown(int button);
    static bool isKeyUp(int button);
    static bool isKeyHeld(int button);

private:
    // while down
    static bool keys_held[];
    // just press
    static bool keys_down[];
    // just release
    static bool keys_up[];
};

#endif