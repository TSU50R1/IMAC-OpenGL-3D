#include "Scene.hpp"
#include <iostream>

Scene::Scene(const std::string filename) : m_afficher_cle(true){
    //initialisation de la classe scene, avec chargement du fichier .conf
    //récupération du nombre de shaders et de models à charger dans la scene
    m_IniFile.mapPath(filename);
    m_nbModels = std::stoi(m_IniFile.getString("global.nb_models"));
    m_nbShaders = std::stoi(m_IniFile.getString("global.nb_shaders"));
    m_nbPointLights = std::stoi(m_IniFile.getString("global.nb_point_lights"));
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
    m_cle = new Model(m_IniFile.getString("cle.models_directory"));
    m_shader_cle = new Shader(m_IniFile.getString("shader0.shader_directory_vertex").c_str(),m_IniFile.getString("shader0.shader_directory_fragment").c_str());
    m_shader_light = new Shader(m_IniFile.getString("shader1.shader_directory_vertex").c_str(),m_IniFile.getString("shader1.shader_directory_fragment").c_str());
    m_shader_light->use();

    m_shader_light->setInt("material.diffuse", 0);
    m_shader_light->setInt("material.specular", 1);

}

void Scene::renderScene(const glm::mat4 &projection, const glm::mat4 &view ){


            for (size_t j = 0; j<m_nbPointLights; j++) {
                
                // point light
                m_shader_light->setVec3("pointLights[j].position", glm::vec3(std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".position_x")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".position_y")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".position_z"))
                                            ));
                m_shader_light->setVec3("pointLights[j].ambient", glm::vec3(std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".ambient_r")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".ambient_g")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".ambient_b"))
                                            ));
                m_shader_light->setVec3("pointLights[j].diffuse", glm::vec3(std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".diffuse_r")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".diffuse_g")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".diffuse_b"))
                                            ));
                m_shader_light->setVec3("pointLights[j].specular", glm::vec3(std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".specular_r")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".specular_g")),
                                                                                std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".specular_b"))
                                            ));
                m_shader_light->setFloat("pointLights[j].constant", std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".constant")));
                m_shader_light->setFloat("pointLights[j].linear", std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".linear")));
                m_shader_light->setFloat("pointLights[j].quadratic", std::stof(m_IniFile.getString("pointlight" + std::to_string(j) + ".quadratic")));

            }
                


     for (size_t i= 0; i<m_nbModels; i++){

        //le .conf indique quel shader utiliser pour chaque model
        int num_shader = std::stoi(m_IniFile.getString("model" +  std::to_string(i) +".num_shader"));
        m_shaders[num_shader]->use();
        m_shaders[num_shader]->setMat4("projection", projection);
        m_shaders[num_shader]->setMat4("view", view);

        m_shader_light->use();
        m_shader_light->setMat4("projection", projection);
        m_shader_light->setMat4("view", view);   

        m_shader_light->setInt("material.diffuse", 0.2);
        m_shader_light->setInt("material.specular", 1.); 


        m_shader_light->setVec3("dirLight.direction", 0.5f, -0.5f, -0.5f);
        m_shader_light->setVec3("dirLight.ambient", 0.7f, 0.2f, 0.5f);
        m_shader_light->setVec3("dirLight.diffuse", 0.7f, 0.4f, 0.4f);
        m_shader_light->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);    

        // rendu du model chargé à partir des valeurs de transformation données dans les fichier
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
        m_shader_light->setMat4("model", model);
        m_models[i]->Draw(*m_shaders[num_shader]);
        m_models[i]->Draw(*m_shader_light);
    }


    if(m_afficher_cle) {
        //le .conf indique quel shader utiliser pour chaque model
        m_shader_cle->use();
        m_shader_cle->setMat4("projection", projection);
        m_shader_cle->setMat4("view", view);

        // rendu du model chargé à partir des valeurs de transformation données dans les fichier
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(std::stof(m_IniFile.getString("cle.translate_x")),
                                                std::stof(m_IniFile.getString("cle.translate_y")),
                                                std::stof(m_IniFile.getString("cle.translate_z"))
        ));
        float angleRad = glm::radians(std::stof(m_IniFile.getString("cle.radians")));
        model = glm::rotate(model, angleRad, glm::vec3(std::stoi(m_IniFile.getString("cle.rotate_x")),
                                                       std::stoi(m_IniFile.getString("cle.rotate_y")),
                                                       std::stoi(m_IniFile.getString("cle.rotate_z"))
        ));

        model = glm::scale(model, glm::vec3(std::stof(m_IniFile.getString("cle.scale_x")),
                                            std::stof(m_IniFile.getString("cle.scale_y")),
                                            std::stof(m_IniFile.getString("cle.scale_z"))
        ));
        m_shader_cle->setMat4("model", model);
        m_cle->Draw(*m_shader_cle);
    }
}
