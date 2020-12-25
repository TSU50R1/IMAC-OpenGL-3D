#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/*class Light {

    public:
    
    glm::vec3 direction;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    
    Light(const char* vertexPath, const char* fragmentPath);
    // activate the shader
    // ------------------------------------------------------------------------
    
    inline void setMat4(const std::string &name, const glm::mat4 &mat) const{
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
};
*/