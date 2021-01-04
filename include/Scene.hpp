#pragma once
#include "myShader.hpp"
#include "Model.hpp"
#include "LoadINI.hpp"
#include "FreeflyCamera.hpp"
#include <string>
#include <vector>

class Scene {
public:
    size_t m_nbModels;
    size_t m_nbShaders;
    IniLoadMap m_IniFile;
    std::vector<Model*> m_models;
    std::vector<imacity::Shader*> m_shaders;
    Model* m_cle;
    imacity::Shader* m_shader_cle;
    imacity::Shader* m_shader_light;
    bool m_afficher_cle;

public:
    Scene(const std::string filename);
    ~Scene();

    void loadScene();
    void renderScene(const glm::mat4 &projection, const glm::mat4 &view);
    glm::mat4 rendering(const std::string model_to_render, const glm::mat4 &projection, const glm::mat4 &view);

    inline void set_afficher_cle(const bool afficher_cle){m_afficher_cle = afficher_cle;}

    void enlight(const glm::mat4 &projection, const glm::mat4 &view ,const imacity::FreeflyCamera &camera);
};
