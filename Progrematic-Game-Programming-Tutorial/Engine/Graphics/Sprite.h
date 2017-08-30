#ifndef __PGMT_ENGINE_GRAPHICS__SPRITE_H__
#define __PGMT_ENGINE_GRAPHICS__SPRITE_H__

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

#include "Texture.h"
#include "../Engine.h"

class Sprite {
public:
    Sprite();
    Sprite(std::string imagePath);
    Sprite(string imagePath, float _pos_x, float _pos_y);

    void update();
    void render();

    void setPos(float x, float y);
    void setRot(float rot);
    void setScale(float s);
    void setScale(float x, float y);
    void setSpeed(float speed);

    void addRotation(float rot);
    void addSpeed(float speed);
    void moveBy(float x, float y);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    float getPosX() const { return pos_x; }
    float getPosY() const { return pos_x; }

private:
    Texture texture;
    float pos_x, pos_y;
    float scl_x, scl_y;

    float rot;
    float speed;
};

#endif