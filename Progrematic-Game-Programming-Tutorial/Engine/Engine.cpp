#include "Engine.h"
#include <iostream>

using namespace std;

int Engine::screen_width = 1024;
int Engine::screen_height = 768;
GLFWwindow *Engine::window = NULL;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::initilize(char *windowTitle) {
    if (!glfwInit()) {
        cerr << "Error initilizing GLFW" << endl;

        return false;
    }

    window = glfwCreateWindow(screen_width, screen_height, windowTitle, NULL, NULL);

    if (window == NULL) {
        cerr << "Error in creating window" << endl;

        return false;
    }

    // OpenGL setup

    glfwMakeContextCurrent(window);

    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    glfwSwapInterval(1);

    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int x_pos = (mode->width - screen_width) / 2;
    int y_pos = (mode->height - screen_height) / 2;
    glfwSetWindowPos(window, x_pos, y_pos);

    // GL Setup
    //View port

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);

    //Alpha Blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

void Engine::update() {
    glfwPollEvents();
}

void Engine::pre_render() {
    pre_render(0, 1, 0, 1);
}

void Engine::pre_render(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::post_render() {
    glfwSwapBuffers(window);
}
