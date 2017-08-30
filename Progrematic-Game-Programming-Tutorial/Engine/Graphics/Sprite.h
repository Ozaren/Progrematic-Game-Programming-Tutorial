#ifndef TWITCH_SPRITE
#define TWITCH_SPRITE

#include <iostream>
#include <string>

#include "GLFW/glfw3.h"
#include "Texture.h"

class Sprite {
public:
    Sprite();
    Sprite(std::string imagePath);
    Sprite(string imagePath, float _pos_x, float _pos_y);

    void update();
    void render();

private:
    Texture texture;
    float pos_x, pos_y;
};

#endif