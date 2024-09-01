//
// Created by george on 28/08/24.
//

#ifndef BUILDER_BLOCKSHADER_H
#define BUILDER_BLOCKSHADER_H

#include <string>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class BlockShader {
private:
    unsigned int id;

    static unsigned int compileShader(std::string &source, GLuint type);
public:
    BlockShader();

    void use() const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    ~BlockShader() { glDeleteProgram(id); }
};

#endif //BUILDER_BLOCKSHADER_H
