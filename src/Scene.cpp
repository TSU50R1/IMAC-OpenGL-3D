#include "Scene.hpp"
#include <iostream>
#include <glm/glm.hpp>

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
    m_shader_cle = new imacity::Shader(m_IniFile.getString("shader0.shader_directory_vertex").c_str(),m_IniFile.getString("shader0.shader_directory_fragment").c_str());

    m_shader_light = new imacity::Shader("shaders/lightning.vs.glsl", "shaders/lightning.fs.glsl");

}



void Scene::renderScene(const glm::mat4 &projection, const glm::mat4 &view ){
    for (size_t i= 0; i<m_nbModels; i++){
    //The .conf indicates which shader to use for each model.
    int num_shader = std::stoi(m_IniFile.getString("model" + std::to_string(i) +".num_shader"));
        for (size_t j= 0; j < m_nbShaders; j++) {
            //m_shaders[j]->use();
            //m_shaders[j]->setMat4("projection", projection);
            //m_shaders[j]->setMat4("view", view);
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

void Scene::enlight(const glm::mat4 &projection, const glm::mat4 &view ,const imacity::FreeflyCamera &camera) {

    glm::vec3 pointLightPositions[] = {
            glm::vec3( 1.9f,  -0.8f,  -3.0f),
            glm::vec3( 1.4f, -0.2f, -58.4f),
            glm::vec3(1.4f,  -0.3f, -61.0f),
            glm::vec3( 1.7f,  -0.3f, -61.2f)
        };

        //modelShader.use();
        m_shader_light->use();
        m_shader_light->setInt("material.diffuse", 0.2);
        m_shader_light->setInt("material.specular", 1.);


        /// directional light
        m_shader_light->setVec3("dirLight.direction", 0.5f, -0.5f, -0.5f);
        m_shader_light->setVec3("dirLight.ambient", 0.7f, 0.2f, 0.5f);
        m_shader_light->setVec3("dirLight.diffuse", 0.7f, 0.4f, 0.4f);
        m_shader_light->setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        // point light 1
        m_shader_light->setVec3("pointLights[0].position", pointLightPositions[0]);
        m_shader_light->setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        m_shader_light->setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        m_shader_light->setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        m_shader_light->setFloat("pointLights[0].constant", 1.0f);
        m_shader_light->setFloat("pointLights[0].linear", 0.09);
        // point light 2
        m_shader_light->setVec3("pointLights[1].position", pointLightPositions[1]);
        m_shader_light->setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        m_shader_light->setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        m_shader_light->setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        m_shader_light->setFloat("pointLights[1].constant", 1.0f);
        m_shader_light->setFloat("pointLights[1].linear", 0.09);
        m_shader_light->setFloat("pointLights[1].quadratic", 0.032);
        // point light 3
        m_shader_light->setVec3("pointLights[2].position", pointLightPositions[2]);
        m_shader_light->setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        m_shader_light->setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
        m_shader_light->setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        m_shader_light->setFloat("pointLights[2].constant", 1.0f);
        m_shader_light->setFloat("pointLights[2].linear", 0.09);
        m_shader_light->setFloat("pointLights[2].quadratic", 0.032);
        // point light 4
        m_shader_light->setVec3("pointLights[3].position", pointLightPositions[3]);
        m_shader_light->setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
        m_shader_light->setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        m_shader_light->setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        m_shader_light->setFloat("pointLights[3].constant", 1.0f);
        m_shader_light->setFloat("pointLights[3].linear", 0.09);
        m_shader_light->setFloat("pointLights[3].quadratic", 0.032);
        // spotLight
        m_shader_light->setVec3("spotLight.position", camera.get_Position());
        m_shader_light->setVec3("spotLight.direction", camera.m_FrontVector);
        m_shader_light->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        m_shader_light->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        m_shader_light->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        m_shader_light->setFloat("spotLight.constant", 1.0f);
        m_shader_light->setFloat("spotLight.linear", 0.09);
        m_shader_light->setFloat("spotLight.quadratic", 0.032);
        m_shader_light->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        m_shader_light->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f))); 


        m_shader_light->setMat4("projection", projection);
        m_shader_light->setMat4("view", view);
}

void Scene::delete_scene(){
    for (size_t i = 0; i<m_nbModels; i++ ){
        std::cout << "model supprimé" << std::endl;
        delete m_models[i];
    }
    for (size_t i = 0; i <m_nbShaders; i++){
        delete m_shaders[i];
    }
}

