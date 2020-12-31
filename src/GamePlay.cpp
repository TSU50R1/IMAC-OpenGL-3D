#include <iostream>
#include <string>

#include "GamePlay.hpp"

GamePlay::GamePlay() :m_check_zone(false),
                        m_ramasser_cle(false),
                        m_nb_scenes(4){

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
    m_nb_zones_cle = std::stoi(m_File_Description_Zones.getString("global.m_nb_zones_cle"));

    m_cles.insert( std::pair<std::string, bool>("cle0",false) );
    m_cles.insert( {"cle1", false} );
    m_cles.insert( {"cle2", false} );
    m_cles.insert( {"cle3", false} );
}

GamePlay::~GamePlay(){};

//vérifie si la caméra est dans une zone
bool GamePlay::est_dans_zone(const FreeflyCamera &camera, float x_zone, float z_zone,  float R){
    if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))<=R){
        std::cout << "Est dans la zone" << std:: endl;
        return true;
    }else{
        return false;
    }
}

//rendu des scenes en fonction des booléens
void GamePlay::drawScene(const glm::mat4 &projection, const glm::mat4 &view ){

    for (size_t i = 0; i<m_nb_scenes; i++){
        if (m_afficher_scene[i])
            m_scenes[i]->renderScene(projection, view);
    }

}

//chargement des scenes
void GamePlay::loadScenes (){
    for (size_t i = 0; i<m_nb_scenes; i++){
        m_scenes[i] -> loadScene();
    }
}

bool GamePlay::possede_cle (const int i){
    assert (i >=0 && i<= 3 && "Numero de clé incorrect");
    return m_cles ["cle"+std::to_string(i)];
}

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

void GamePlay::changement_scene(const int numero_scene){
    assert (numero_scene <4 && numero_scene >=0 && "Numero de scene incorrect");
    for (size_t i = 0; i< m_nb_scenes; i++){
        m_afficher_scene[i] = false;
    }
    m_afficher_scene[numero_scene] = true;
}


