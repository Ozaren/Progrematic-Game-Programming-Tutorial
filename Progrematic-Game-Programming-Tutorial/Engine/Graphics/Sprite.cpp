#include "Sprite.h"

using namespace std;

Sprite::Sprite()
    : pos_x(0), pos_y(0), rot(0), scl_x(1), scl_y(1), speed(0), texture(Texture()) {

}

Sprite::Sprite(string imagePath)
    : pos_x(0), pos_y(0), rot(0), scl_x(1), scl_y(1), speed(0), texture(Texture(imagePath)) {

}

Sprite::Sprite(string imagePath, float _pos_x, float _pos_y)
    : pos_x(_pos_x), pos_y(_pos_y), rot(0), scl_x(1), scl_y(1), speed(0), texture(Texture(imagePath)) {

}

void Sprite::setPos(float _x, float _y) {
    pos_x = _x;
    pos_y = _y;
}

void Sprite::setRot(float _rot) {
    rot = _rot;
}

void Sprite::setScale(float s) {
    setScale(s, s);
}

void Sprite::setScale(float _x, float _y) {
    scl_x = _x;
    scl_y = _y;
}

void Sprite::setSpeed(float _speed) {
    speed = _speed;
}

void Sprite::moveBy(float _x, float _y) {
    pos_x += _x * Engine::getDT();
    pos_y += _y * Engine::getDT();
}

void Sprite::addRotation(float _rot) {
    rot += _rot * Engine::getDT();
}

void Sprite::addSpeed(float _speed) {
    speed += _speed;
}

void Sprite::moveUp() {
    pos_y += speed * Engine::getDT();
}

void Sprite::moveDown() {
    pos_y -= speed * Engine::getDT();
}

void Sprite::moveRight() {
    pos_x -= speed * Engine::getDT();
}

void Sprite::moveLeft() {
    pos_x += speed * Engine::getDT();
}

void Sprite::update() {

}

void Sprite::render() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.getID());
    glLoadIdentity();

    //TRANSLATE -> ROTATE -> SCALE
    glTranslatef(pos_x, pos_y, 0);
    glRotatef(rot, 0, 0, 1);
    glScalef(scl_x, scl_y, 1);

    //Rendering

    int width, height;

    width = texture.getWidth();
    height = texture.getHeight();
    glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);        glVertex2i(0, 0);
    glTexCoord2f(1, 0);        glVertex2i(width, 0);
    glTexCoord2f(1, 1);        glVertex2i(width, height);
    glTexCoord2f(0, 1);        glVertex2i(0, height);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
