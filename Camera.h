//
// Created by george on 27/08/24.
//

#ifndef BUILDER_CAMERA_H
#define BUILDER_CAMERA_H

#include "Display.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    glm::mat4 view;
//    glm::vec3 pos {5.0f, 5.0f, 5.0f};
    glm::vec3 posOffset;
    glm::vec3 focus {0.0f, 0.0f, 0.0f};
    glm::mat4 projection;

    static inline const glm::vec3 UP {0.0f, 1.0f, 0.0f};
    double speed {1.0};
    double sensitivity {0.1f};

    float pitch {0.0f}, yaw {-90.0f};
    double lastMouseX, lastMouseY;
    bool looking {false};
    // Distance between the camera and the focus
    float orbitRadius {5.0f};

    Display& scr;

    static glm::vec3 calcOffset(float pitch, float yaw, float radius);

    void moveFocus();
    void look();
public:
    explicit Camera(Display& pScr);

    [[nodiscard]] const glm::mat4& getView() const { return view; }
    [[nodiscard]] const glm::mat4& getPerspective() const { return projection; }

    void update();
};


#endif //BUILDER_CAMERA_H
