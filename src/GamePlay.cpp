#include <iostream>
#include <string>
#include <cmath>

#include "GamePlay.hpp"

GamePlay::GamePlay() :m_check_zone(false),
                        m_peut_ramasser(false),
                        m_nb_scenes(4),
                        m_check_scene_limite(true){

    m_scenes.push_back(new Scene("ini_files/Scene1.conf"));
    m_scenes.push_back(new Scene("ini_files/Scene2.conf"));
    m_scenes.push_back(new Scene("ini_files/Scene3.conf"));
    m_scenes.push_back(new Scene("ini_files/Scene4.conf"));

    m_afficher_scene.push_back(true);
    m_afficher_scene.push_back(false);
    m_afficher_scene.push_back(false);
    m_afficher_scene.push_back(false);

    m_peut_entrer_scene.push_back(false);
    m_peut_entrer_scene.push_back(false);
    m_peut_entrer_scene.push_back(false);
    m_peut_entrer_scene.push_back(false);

    //chargement du fichier de description des zones
    m_File_Description_Zones.mapPath("ini_files/Description_zones.conf");
    m_nb_zones_portes = std::stoi(m_File_Description_Zones.getString("global.m_nb_zones_portes"));

    m_cles.insert( std::pair<std::string, bool>("cle0",false) );
    m_cles.insert( {"cle1", false} );
    m_cles.insert( {"cle2", false} );
    m_cles.insert( {"cle3", false} );
}

GamePlay::~GamePlay(){};

//vérifie si la caméra est dans une zone
bool GamePlay::est_dans_zone(const FreeflyCamera &camera, float x_zone, float z_zone,  float R){
    if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))<=R){
        return true;
    }else{
        return false;
    }
}

//rendu des scenes en fonction des booléens
void GamePlay::drawScene(const glm::mat4 &projection, const glm::mat4 &view ){

    for (size_t i = 0; i<m_nb_scenes; i++){
        //if (m_afficher_scene[i])
            m_scenes[i]->renderScene(projection, view);
    }

}

//chargement des scenes
void GamePlay::loadScenes (){
    for (size_t i = 0; i<m_nb_scenes; i++){
        m_scenes[i] -> loadScene();
    }
}

//verifie si la clé a bien été ramassé
bool GamePlay::possede_cle (const int i){
    assert (i >=0 && i<= 3 && "Numero de clé incorrect");
    if (i == 0)
        return m_cles["cle3"];
    if (i == 1)
        return m_cles["cle0"];
    if (i == 2)
        return m_cles["cle1"];
    if (i == 3)
        return m_cles["cle2"];

}

//parcourt toutes les zones possibles de portes decrites dans le .conf et active la possibilité d'entrer
void GamePlay::verifie_zones_portes(const FreeflyCamera &camera){
    for (size_t i = 0; i< m_nb_zones_portes; i++){
        m_peut_entrer_scene[i] = false;
        if (est_dans_zone(camera, std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".x")),
                                  std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".z")),
                                  std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".r")))){
            m_peut_entrer_scene[i] = true;
        }
    }
}

void GamePlay::est_dans_scene( FreeflyCamera &camera, const int i){
    assert (i>=0 && i<4 && "numerode scene incorrect");
   // m_check_scene_limite =  true;
    float x_zone = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".x"));
    float z_zone = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".z"));
    float R = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".r"));
    float pas_recul = 0.07;
        if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))<=R){
            m_check_scene_limite =  true;
            std::cout << "en dans de la zone" << std::endl;
        }else{
             m_check_scene_limite = false;
             std::cout << "en dehors de la zone" << std::endl;
             //si on arrive sur la limite du deplacement, il faut reculer la camera dans la direction formé par le vecteur entre
             //la position courante et le centre de la scene
             camera.set_Position(camera.get_Position().x-pas_recul*(camera.get_Position().x-x_zone),0.0,camera.get_Position().z- pas_recul*(camera.get_Position().z-z_zone));
        }
}

void GamePlay::reste_dans_scene( FreeflyCamera &camera){
    for(int i = 1; i<m_nb_scenes; i++){
        if (m_afficher_scene[i])
            est_dans_scene(camera, i);
    }
}

void GamePlay::verifie_zone_cle(const FreeflyCamera &camera){
        m_peut_ramasser = false;
        if (est_dans_zone(camera, std::stof(m_File_Description_Zones.getString("zone_cle1.x")),
                          std::stof(m_File_Description_Zones.getString("zone_cle1.z")),
                          std::stof(m_File_Description_Zones.getString("zone_cle1.r")))){
            m_peut_ramasser = true;
        }
}

//permet le changement de scene
void GamePlay::changement_scene(const int numero_scene, FreeflyCamera &camera){
    assert (numero_scene <4 && numero_scene >=0 && "Numero de scene incorrect");
    for (size_t i = 0; i< m_nb_scenes; i++){
        m_afficher_scene[i] = false;
        m_peut_entrer_scene[i] = false;
    }
    m_afficher_scene[numero_scene] = true;
    this->set_camera_new_scene(camera, numero_scene);
}

//récupération de la clé et desactivation de son affichage dans sa scene
void GamePlay::recupere_cle(const int i){
    m_cles["cle"+std::to_string(i)] = true;
    m_scenes[i]->set_afficher_cle(false);
}

void GamePlay::fin_jeu(){
    std::cout << "Vous avez réussi à entrer dans le chateau !! " << std::endl;
    m_afficher_scene[0] = false;
}

void GamePlay::set_camera_new_scene(FreeflyCamera &camera,const int i){
    assert (i <4 && i >=0 && "Numero de scene incorrect");
    camera.set_Position(std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".x")),
                        0.0,
                       std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".z")));
}
