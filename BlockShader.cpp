//
// Created by george on 28/08/24.
//

#include "BlockShader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string_view>

BlockShader::BlockShader() {
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open files
        vShaderFile.open("/home/george/CLionProjects/block-putter/vertex.glsl");
        fShaderFile.open("/home/george/CLionProjects/block-putter/fragment.glsl");
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

    // Compile shaders
    unsigned int vertex, fragment;
    const char * vShaderCode {vertexCode.c_str()};
    const char * fShaderCode {fragmentCode.c_str()};
//    vertex = compileShader(vertexCode, GL_VERTEX_SHADER);
//    fragment = compileShader(fragmentCode, GL_FRAGMENT_SHADER);
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
//    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
//    checkCompileErrors(fragment, "FRAGMENT");

    // Link shaders
    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    // Delete the shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void BlockShader::use() const {
    glUseProgram(id);
}

void BlockShader::setVec4(const std::string &name, const glm::vec4 &value) const {
    glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
}

void BlockShader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

unsigned int BlockShader::compileShader(std::string &source, GLuint type) {
    unsigned int shader = glCreateShader(type);
    const char* rawSource = source.c_str();
    glShaderSource(shader, 1, &rawSource, nullptr);
    glCompileShader(shader);

    return shader;
}
