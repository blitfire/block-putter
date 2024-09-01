#include "Display.h"
#include "Camera.h"
#include "init.h"
#include "Block.h"

int main() {
    init();
    Display screen;
    Camera cam {screen};
    Block test {0, 0, 0, {1.0f, 0.0f, 0.0f, 1.0f}, cam.getPerspective()};

    while (!screen.keyPressed(GLFW_KEY_ESCAPE)) {
        cam.update();
        test.render(cam.getView());
        screen.update();
    }
    screen.close();
    return 0;
}
