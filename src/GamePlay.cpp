#include <iostream>
#include <string>

#include "GamePlay.hpp"

GamePlay::GamePlay() :m_check_zone(false),
                        m_peut_ramasser(false),
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

bool GamePlay::est_dans_scene(const FreeflyCamera &camera, const int i){
    float x_zone = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".x"));
    float z_zone = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".y"));
    float R = std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".r"));
        if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))>=R){
            return true;
        }else{
            return false;
        }
}

bool GamePlay::reste_dans_scene(const FreeflyCamera &camera){
    for(int i = 0; i<m_nb_scenes; i++){
        if (m_afficher_scene[i])
            return est_dans_scene(camera, i);
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
void GamePlay::changement_scene(const int numero_scene){
    assert (numero_scene <4 && numero_scene >=0 && "Numero de scene incorrect");
    for (size_t i = 0; i< m_nb_scenes; i++){
        m_afficher_scene[i] = false;
        m_peut_entrer_scene[i] = false;
    }
    m_afficher_scene[numero_scene] = true;
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

