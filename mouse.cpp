//
// Created by george on 27/08/24.
//

#include "mouse.h"

void mouse::callback(GLFWwindow *window, double xpos, double ypos) {
    Mouse::getMouse().x = xpos;
    Mouse::getMouse().y = ypos;
}