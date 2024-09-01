//
// Created by george on 27/08/24.
//

#include "Block.h"
#include "Camera.h"
#include <iostream>

Block::Block(int x, int y, int z, const glm::vec4 &pColour, const glm::mat4 &pProj) :
    colour{pColour},
    projection{pProj},
    // Sorting out the world space transformation.
    // x, y and z are in units of blocks for simplicity
    pos{glm::translate(glm::mat4{1.0f},
                       {static_cast<float>(x), static_cast<float>(y), static_cast<float>(z)})} {

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // unbind
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Block::render(const glm::mat4 &view) {
    shader.use();
    shader.setMat4("model", pos);
    shader.setMat4("view", view);
    shader.setMat4("projection", projection);
    shader.setVec4("colour", colour);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

    glBindVertexArray(0);
}

Block::~Block() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

