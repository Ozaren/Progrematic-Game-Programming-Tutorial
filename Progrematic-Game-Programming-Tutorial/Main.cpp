#include <iostream>

#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"

using namespace std;

int main() {
    cout << "Start Window" << endl;

    Engine engine;
    bool pass_init = engine.initilize("Test Window");

    // Avg FPS Vars
    double avgDT[100];
    int length(sizeof(avgDT) / sizeof(*avgDT));
    int len(0);
    int index(0);

    Sprite sprite("Assets/Art/bird 2 - Edit.png", 100, 100);
    
    sprite.setScale(.3f);
    sprite.setSpeed(200);

    while (true) {
        engine.update();

        if (Mouse::isButtonHeld(GLFW_MOUSE_BUTTON_MIDDLE)) {
            sprite.setPos((float)Mouse::getMouseX(), (float)Mouse::getMouseY());
        }

        if (Mouse::isButtonHeld(GLFW_MOUSE_BUTTON_LEFT)) {
            sprite.addRotation(10);
        }

        if (Mouse::isButtonHeld(GLFW_MOUSE_BUTTON_RIGHT)) {
            sprite.addRotation(-10);
        }

        if (Keyboard::isKeyHeld(GLFW_KEY_W)) {
            sprite.moveUp();
        }

        if (Keyboard::isKeyHeld(GLFW_KEY_A)) {
            sprite.moveRight();
        }

        if (Keyboard::isKeyHeld(GLFW_KEY_S)) {
            sprite.moveDown();
        }

        if (Keyboard::isKeyHeld(GLFW_KEY_D)) {
            sprite.moveLeft();
        }

        sprite.update();

        engine.pre_render();

        sprite.render();

        engine.post_render();

        // Average FPS Calculation
        avgDT[index] = Engine::getDT();

        if (len < length)
            len++;
        index = (index + 1) % length;

        double avg(0);
        for (int i = 0; i < len; i++) {
            avg += avgDT[i];
        }

        avg /= len;
        cout << "DT: " << Engine::getDT() << 
                "\t AVG DT: " << avg << 
                "\tFPS: " << 1 / Engine::getDT() << 
                "\t AVG FPS: " << 1 / avg << "\r";
    }

    return 0;
}