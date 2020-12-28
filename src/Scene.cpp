#include "Scene.hpp"
#include <iostream>

Scene::Scene(const std::string filename){
    //initialisation de la classe scene, avec chargement du fichier .conf
    //récupération du nombre de shaders et de models à charger dans la scene
    m_IniFile.mapPath(filename);
    m_nbModels = std::stoi(m_IniFile.getString("global.nb_models"));
    m_nbShaders = std::stoi(m_IniFile.getString("global.nb_shaders"));
}

Scene::~Scene(){};

void Scene::loadScene(){
    //on charge ici à partir des chemins fournits dans les .conf tous les shaders et tous les models
    //et on les stockes dans une liste
    for (size_t i= 0; i<m_nbModels; i++ ) {
        m_models.push_back(new Model(m_IniFile.getString("model" + std::to_string(i) + ".models_directory")));
        std::cout << "model " << i << " ajouté" << std::endl;
    }
    for (size_t i= 0; i<m_nbShaders; i++ ){
        m_shaders.push_back( new Shader(m_IniFile.getString("shader" +  std::to_string(i) + ".shader_directory_vertex").c_str(), m_IniFile.getString("shader" +  std::to_string(i) + ".shader_directory_fragment" ).c_str()));
        std::cout << "shader " << i << " ajouté" << std::endl;
    }
}

void Scene::renderScene(glm::mat4 &projection, glm::mat4 &view ){
    for (size_t i= 0; i<m_nbModels; i++){
        //le .conf indique quel shader utiliser pour chaque model
        int num_shader = std::stoi(m_IniFile.getString("model" +  std::to_string(i) +".num_shader"));
        m_shaders[num_shader]->use();
        m_shaders[num_shader]->setMat4("projection", projection);
        m_shaders[num_shader]->setMat4("view", view);

        // rendu du model charcher à partir des valeurs de transformation données dans les fichier
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model,glm::vec3(std::stof(m_IniFile.getString("model" +  std::to_string(i) +".translate_x")),
                                                  std::stof(m_IniFile.getString("model" +  std::to_string(i) +".translate_y")),
                                                  std::stof(m_IniFile.getString("model" +  std::to_string(i) +".translate_z"))
                                                  ));
        float angleRad = glm::radians(std::stof(m_IniFile.getString("model" +  std::to_string(i) +".radians")));
        model = glm::rotate(model, angleRad, glm::vec3(std::stoi(m_IniFile.getString("model" +  std::to_string(i) +".rotate_x")),
                                                       std::stoi(m_IniFile.getString("model" +  std::to_string(i) +".rotate_y")),
                                                       std::stoi(m_IniFile.getString("model" +  std::to_string(i) +".rotate_z"))
        ));

        model = glm::scale(model,glm::vec3(std::stof(m_IniFile.getString("model" +  std::to_string(i) +".scale_x")),
                                               std::stof(m_IniFile.getString("model" +  std::to_string(i) +".scale_y")),
                                               std::stof(m_IniFile.getString("model" +  std::to_string(i) +".scale_z"))
        ));
        m_shaders[num_shader]->setMat4("model", model);
        m_models[i]->Draw(*m_shaders[num_shader]);
    }
}