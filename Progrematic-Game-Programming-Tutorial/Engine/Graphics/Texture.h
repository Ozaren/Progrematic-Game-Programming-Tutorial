#ifndef TWITCH_TEXTURE
#define TWITCH_TEXTURE

#include "GLFW/glfw3.h"
#include "SOIL/src/SOIL.h"

#include <iostream>
#include <string>

using namespace std;

class Texture {
public:
	Texture();
	Texture(int id);
	Texture(string path);

	int getID();
	int getWidth();
	int getHeight();

private:
	bool loadImage();

	int id;
	int width;
	int height;
};

#endif