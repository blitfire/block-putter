//
// Created by george on 27/08/24.
//

#ifndef BUILDER_BLOCK_H
#define BUILDER_BLOCK_H

#include "BlockShader.h"
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Block {
private:
    // Local space coordinates
    static inline const float vertices[24] = {
            0.0f, 0.0f, 0.0f, // 0
            1.0f, 0.0f, 0.0f, // 1
            1.0f, 0.0f, 1.0f, // 2
            0.0f, 0.0f, 1.0f, // 3
            0.0f, 1.0f, 0.0f, // 4
            1.0f, 1.0f, 0.0f, // 5
            1.0f, 1.0f, 1.0f, // 6
            0.0f, 1.0f, 1.0f // 7
    };
    static inline const unsigned int indices[36] = {
            0, 1, 2,
            0, 3, 2,
            4, 5, 6,
            4, 7, 6,
            0, 4, 5,
            0, 1, 5,
            1, 5, 6,
            1, 2, 6,
            2, 6, 7,
            2, 4, 7,
            3, 7, 4,
            3, 0, 4
    };

    // Colour gets passed to the shader
    glm::vec4 colour;
    glm::mat4 pos {1.0f};
    const glm::mat4& projection;

    GLuint VAO, VBO, EBO;
    const BlockShader shader {};

public:
    Block(int x, int y, int z, const glm::vec4 &pColour, const glm::mat4 &pProj);
    void setColour(const glm::vec4& pColour) { colour = pColour; }
    void render(const glm::mat4 &camView);

    ~Block();
};


#endif //BUILDER_BLOCK_H
