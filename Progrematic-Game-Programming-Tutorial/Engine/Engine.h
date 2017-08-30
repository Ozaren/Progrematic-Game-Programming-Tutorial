#ifndef __PGMT_ENGINE__ENGINE_H__
#define __PGMT_ENGINE__ENGINE_H__

#include <GLFW\glfw3.h>

#pragma comment(lib, "opengl32.lib")

class Engine {
public:
    static int screen_width;
    static int screen_height;

    Engine();
    ~Engine();

    bool initilize(char *windowTitle);

    void update();
    // default white background
    void pre_render();
    // custom background color
    void pre_render(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
    void post_render();

private:
    static GLFWwindow *window;
};

#endif