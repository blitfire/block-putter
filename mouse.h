//
// Created by george on 27/08/24.
//

#ifndef BUILDER_MOUSE_H
#define BUILDER_MOUSE_H

#include "glad.h"
#include <GLFW/glfw3.h>

namespace {
    class Mouse {
    private:
        Mouse() = default;
    public:
        double x, y;

        Mouse(const Mouse&) = delete;
        Mouse &operator=(const Mouse&) = delete;

        static Mouse &getMouse() {
            static Mouse globMouse;
            return globMouse;
        }
    };
}

namespace mouse {
    void callback(GLFWwindow *window, double xpos, double ypos);

    inline double x() { return Mouse::getMouse().x; }
    inline double y() { return Mouse::getMouse().y; }
}

#endif //BUILDER_MOUSE_H
