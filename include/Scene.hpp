#pragma once
#include "myShader.hpp"
#include "Model.hpp"
#include "LoadINI.hpp"
#include <string>
#include <vector>

class Scene {
public:
    size_t m_nbModels;
    size_t m_nbShaders;
    IniLoadMap m_IniFile;
    std::vector<Model*> m_models;
    std::vector<Shader*> m_shaders;

public:
    Scene(const std::string filename);
    ~Scene();

    void loadScene();
    void renderScene(glm::mat4 &projection, glm::mat4 &view);
>>>>>>> origin/Classe_Scene
};