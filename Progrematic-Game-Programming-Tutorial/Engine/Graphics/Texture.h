#ifndef __PGMT_ENGINE_GRAPHICS__TEXTURE_H__
#define __PGMT_ENGINE_GRAPHICS__TEXTURE_H__

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