//
// Created by george on 27/08/24.
//

#include "Camera.h"
#include "mouse.h"
#include <iostream>

Camera::Camera(Display &pScr) :
    scr{pScr},
    lastMouseX {mouse::getX()},
    lastMouseY {mouse::getY()} {

    projection = glm::perspective(glm::radians(45.0f),
                                  (float)scr.getWidth() / (float)scr.getHeight(),
                                  0.0f,
                                  100.0f);
    posOffset = calcOffset(pitch, yaw, orbitRadius);
    view = glm::lookAt(focus + posOffset, focus, UP);
}

void Camera::moveFocus() {
    auto realSpeed = static_cast<float>(speed * scr.getFrameDelta());
    glm::vec3 right = glm::normalize(glm::cross(UP, -posOffset));

    glm::vec3 dir {0.0f, 0.0f, 0.0f};
    if (scr.keyPressed(GLFW_KEY_A)) {
        dir -= right;
    } if (scr.keyPressed(GLFW_KEY_D)) {
        dir += right;
    } if (scr.keyPressed(GLFW_KEY_W)) {
        dir += UP;
    } if (scr.keyPressed(GLFW_KEY_S)) {
        dir -= UP;
    }

    // dir is normalised so that the camera is always translated at a stable speed.
    // If it moved in both dimensions it would go faster.
    // We have to make sure dir doesn't have a magnitude of 0 or normalisation won't work
    if (dir.x + dir.y + dir.z != 0.0f) focus += glm::normalize(dir) * realSpeed;
}

void Camera::look() {
    double currentMouseX = mouse::getX();
    double currentMouseY = mouse::getY();

    double xOffset = (currentMouseX - lastMouseX) * sensitivity;
    double yOffset = (lastMouseY - currentMouseY) * sensitivity;

    lastMouseX = currentMouseX;
    lastMouseY = currentMouseY;

    if (scr.mouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
        // Ensures we only hide the cursor once, when the right mouse button is pressed.
        if (!looking) {
            scr.hideCursor();
            looking = true;
        }
        yaw += static_cast<float>(xOffset);
        pitch -= static_cast<float>(yOffset);

        // Keeping yaw in the range just for accuracy's sake (might remove if I decide it's not necessary)
        if (yaw > 180.0f) {
            yaw -= 360.0f;
        } else if (yaw < -180.0f) {
            yaw += 360.0f;
        }

        // Keeping pitch in the right range. This is definitely necessary.
        if (pitch > 89.0f) {
            pitch = 89.0f;
        } else if (pitch < -89.0f) {
            pitch = -89.0f;
        }

        posOffset = calcOffset(pitch, yaw, orbitRadius);
    } else if (looking) {
        // Re-enable the cursor when the right mouse button is lifted
        scr.showCursor();
        looking = false;
    }
}

void Camera::update() {
    moveFocus();
    look();
    view = glm::lookAt(focus + posOffset, focus, UP);
}

glm::vec3 Camera::calcOffset(float pitch, float yaw, float radius) {
    glm::vec3 offset {
        static_cast<float>(cos(glm::radians(yaw) * cos(glm::radians(pitch)))),
        static_cast<float>(sin(glm::radians(pitch))),
        static_cast<float>(sin(glm::radians(yaw)) * cos(glm::radians(pitch)))
    };
    offset *= radius;
    return offset;
}
