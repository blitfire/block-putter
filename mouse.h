//
// Created by george on 27/08/24.
//

#ifndef BUILDER_MOUSE_H
#define BUILDER_MOUSE_H

#include "glad.h"
#include <GLFW/glfw3.h>

class mouse {
private:
    double x, y;

    mouse() = default;
    static mouse &getMouse() {
        static mouse globMouse;
        return globMouse;
    }
public:

    mouse(const mouse&) = delete;
    mouse &operator=(const mouse&) = delete;

    static double getX() { return mouse::getMouse().x; }
    static double getY() { return mouse::getMouse().y; }

    static void callback(GLFWwindow *window, double xpos, double ypos);
};


#endif //BUILDER_MOUSE_H
