//
// Created by george on 27/08/24.
//

#ifndef BUILDER_DISPLAY_H
#define BUILDER_DISPLAY_H

#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Display {
private:
    GLfloat background[3] = {0.149f, 0.584f, 0.788f};
    GLFWwindow *window;
    glm::mat4 projection;

    double lastFrame {0.0f}, deltaTime {0.0f};

public:
    Display();
    [[nodiscard]] bool keyPressed(int key) const { return glfwGetKey(window, key) == GLFW_PRESS; };
    void update();
    void close() { glfwSetWindowShouldClose(window, true); };
    void hideCursor() { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }
    void showCursor() { glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }
    [[nodiscard]] bool mouseButtonPressed(int button) const { return glfwGetMouseButton(window, button) == GLFW_PRESS; }
    [[nodiscard]] double getFrameDelta() const { return deltaTime; }
    [[nodiscard]] const glm::mat4& getPerspective() const { return projection; }

    static void size_callback(GLFWwindow *window, int width, int height);
};


#endif //BUILDER_DISPLAY_H
