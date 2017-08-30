#include "Sprite.h"

using namespace std;

Sprite::Sprite()
    : pos_x(0), pos_y(0), texture(Texture()) {

}

Sprite::Sprite(string imagePath)
    : pos_x(0), pos_y(0), texture(Texture(imagePath)) {

}

Sprite::Sprite(string imagePath, float _pos_x, float _pos_y)
    : pos_x(_pos_x), pos_y(_pos_y), texture(Texture(imagePath)) {

}

void Sprite::update() {

}

void Sprite::render() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.getID());
    glLoadIdentity();

    //TRANSLATE -> ROTATE -> SCALE
    glTranslatef(pos_x, pos_y, 0);

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
