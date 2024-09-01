//
// Created by george on 27/08/24.
//

#include "mouse.h"
#include <iostream>

void mouse::callback(GLFWwindow *window, double xpos, double ypos) {
    mouse::getMouse().x = xpos;
    mouse::getMouse().y = ypos;
}