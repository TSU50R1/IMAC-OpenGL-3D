#include "Scene.hpp"
#include <iostream>

Scene::Scene(const std::string filename) : m_afficher_cle(true){
    //initialization of the scene class, with loading of the .conf file
    //recovering the number of shaders and models to load in the scene
    m_IniFile.mapPath(filename);
    m_nbModels = std::stoi(m_IniFile.getString("global.nb_models"));
    m_nbShaders = std::stoi(m_IniFile.getString("global.nb_shaders"));
}

Scene::~Scene(){};

void Scene::loadScene(){
    //loads here from the paths provided in the .conf all shaders and all models
    //and we store them in a list
    for (size_t i= 0; i<m_nbModels; i++ ) {
        m_models.push_back(new Model(m_IniFile.getString("model" + std::to_string(i) + ".models_directory")));
        std::cout << "model " << i << " ajouté" << std::endl;
    }
    for (size_t i= 0; i<m_nbShaders; i++ ){
        m_shaders.push_back( new imacity::Shader(m_IniFile.getString("shader" +  std::to_string(i) + ".shader_directory_vertex").c_str(), m_IniFile.getString("shader" +  std::to_string(i) + ".shader_directory_fragment" ).c_str()));
        std::cout << "shader " << i << " ajouté" << std::endl;
    }
    m_cle = new Model(m_IniFile.getString("cle.models_directory"));
    m_shader_cle = new imacity::Shader(m_IniFile.getString("shader0.shader_directory_vertex").c_str(),m_IniFile.getString("shader0.shader_directory_fragment").c_str());}

void Scene::renderScene(const glm::mat4 &projection, const glm::mat4 &view ){
    for (size_t i= 0; i<m_nbModels; i++){
    //The .conf indicates which shader to use for each model.
    int num_shader = std::stoi(m_IniFile.getString("model" + std::to_string(i) +".num_shader"));
        for (size_t j= 0; j < m_nbShaders; j++) {
            m_shaders[j]->use();
            m_shaders[j]->setMat4("projection", projection);
            m_shaders[j]->setMat4("view", view);
            m_shaders[j]->setMat4("model", rendering("model" + std::to_string(i), projection, view));
            m_models[i]->Draw(*m_shaders[j]);
        } 
    } if(m_afficher_cle) {
        //The .conf indicates which shader to use for each model.
        m_shader_cle->use();
        m_shader_cle->setMat4("projection", projection);
        m_shader_cle->setMat4("view", view);
        m_shader_cle->setMat4("model", rendering("cle", projection, view));
        m_cle->Draw(*m_shader_cle);
    }
}

glm::mat4 Scene::rendering(const std::string model_to_render, const glm::mat4 &projection, const glm::mat4 &view){
    // rendering of the model loaded with the transformation values given in the files
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model,glm::vec3(std::stof(m_IniFile.getString(model_to_render+".translate_x")),
                                           std::stof(m_IniFile.getString(model_to_render+".translate_y")),
                                           std::stof(m_IniFile.getString(model_to_render+".translate_z"))
    ));
    float angleRad = glm::radians(std::stof(m_IniFile.getString(model_to_render +".radians")));
    model = glm::rotate(model, angleRad, glm::vec3(std::stoi(m_IniFile.getString(model_to_render +".rotate_x")),
                                                   std::stoi(m_IniFile.getString(model_to_render +".rotate_y")),
                                                   std::stoi(m_IniFile.getString(model_to_render+".rotate_z"))
    ));
    model = glm::scale(model,glm::vec3(std::stof(m_IniFile.getString(model_to_render +".scale_x")),
                                       std::stof(m_IniFile.getString(model_to_render+".scale_y")),
                                       std::stof(m_IniFile.getString(model_to_render+".scale_z"))
    ));
    return model;
}
