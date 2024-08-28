#include "Display.h"
#include "Camera.h"
#include "init.h"

int main() {
    init();
    Display screen {100, 100};
    Camera cam {screen};
    while (!screen.keyPressed(GLFW_KEY_ESCAPE)) {
        cam.update();
        screen.update();
    }
    return 0;
}
