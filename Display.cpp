//
// Created by george on 27/08/24.
//

#include "mouse.h"
#include "Display.h"
#include <iostream>

Display::Display() {

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);
    window = glfwCreateWindow(mode->width, mode->height, "Block Putter", monitor, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create window" << std::endl;
        exit(1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, size_callback);
    glfwSetCursorPosCallback(window, mouse::callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialise GLAD." << std::endl;
        exit(1);
    }
    glEnable(GL_DEPTH_TEST);

    projection = glm::perspective(glm::radians(45.0f), (float)mode->width / (float)mode->height, 0.1f, 100.0f);
}

void Display::size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Display::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();

    double currentTime = glfwGetTime();
    deltaTime = currentTime - lastFrame;
    lastFrame = currentTime;

    glClearColor(background[0], background[1], background[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
