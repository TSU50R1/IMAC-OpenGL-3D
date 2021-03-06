#pragma once
#include <glm/gtc/matrix_transform.hpp>

#include "myShader.hpp"

#include <string>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};

class Mesh {
public:
    // mesh Data
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture>      textures;
    unsigned int VAO;

    // constructor
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
         std::vector<Texture> textures);

    // render the mesh
    void Draw(imacity::Shader &shader);

private:
    // render data
    unsigned int VBO, EBO;

    // initializes all the buffer objects/arrays
    void setupMesh();
};
