#include <iostream>

#include "Engine\Engine.h"
#include "Engine\Graphics\Sprite.h"

using namespace std;

int main() {
    cout << "Start Window" << endl;

    Engine engine;
    bool pass_init = engine.initilize("Test Window");

    Sprite sprite("Assets/Art/roof.jpg", 100, 100);

    while (true) {
        engine.update();
        sprite.update();

        engine.pre_render();

        sprite.render();

        engine.post_render();
    }

    return 0;
}