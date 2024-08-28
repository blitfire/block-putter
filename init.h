//
// Created by george on 27/08/24.
//

#ifndef BUILDER_INIT_H
#define BUILDER_INIT_H

#include "glad.h"
#include <GLFW/glfw3.h>

void init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

#endif //BUILDER_INIT_H
