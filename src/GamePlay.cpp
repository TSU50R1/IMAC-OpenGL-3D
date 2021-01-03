#include <iostream>
#include <string>
#include <cmath>

#include "GamePlay.hpp"

////CONSTRUCTOR/DESCTRUCTOR-----------------------------------------------------------
GamePlay::GamePlay() :m_peut_ramasser(false),
                        m_nb_scenes(4),
                        m_check_scene_limite(true){
    //files and booleans initialization
    for(size_t i = 0; i< m_nb_scenes; i++){
        m_scenes.push_back(new Scene("ini_files/Scene"+std::to_string(i+1)+".conf"));
        if (i== 0)
            m_afficher_scene.push_back(true);
        else
            m_afficher_scene.push_back(false);
        m_peut_entrer_scene.push_back(false);
    }
    m_cles.insert( std::pair<std::string, bool>("cle0",false) );
    m_cles.insert( {"cle1", false} );
    m_cles.insert( {"cle2", false} );
    m_cles.insert( {"cle3", false} );

    //charging zone's description file
    m_File_Description_Zones.mapPath("ini_files/Description_zones.conf");
    m_nb_zones_portes = std::stoi(m_File_Description_Zones.getString("global.m_nb_zones_portes"));
}

GamePlay::~GamePlay(){};
////END---------CONSTRUCTOR/DESCTRUCTOR-------------------------------------


////CHECK AREAS----------------------------------------------------
//check if the camera is in a defined zone (a circle of  centre (x_zone, z_zone) and of radius R
bool GamePlay::est_dans_zone(const imacity::FreeflyCamera &camera, float x_zone, float z_zone,  float R){
    if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))<=R){
        return true;
    }else{
        return false;
    }
}

//runs through all the possible door zones described in the .conf and activates the possibility of entering
void GamePlay::verifie_zones_portes(const imacity::FreeflyCamera &camera){
    for (size_t i = 0; i< m_nb_zones_portes; i++){
        m_peut_entrer_scene[i] = false;
        if (est_dans_zone(camera, std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".x")),
                          std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".z")),
                          std::stof(m_File_Description_Zones.getString("zone_porte" +  std::to_string(i) + ".r")))){
            m_peut_entrer_scene[i] = true;
        }
    }
}

//for scenes in the houses, allows you to keep the camera in the room
//the values of the different zones are stored in the file Description_zones.conf
void GamePlay::est_dans_scene(imacity::FreeflyCamera &camera, const int i){
    assert (i>=0 && i<m_nb_scenes && "numerode scene incorrect");
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

void GamePlay::reste_dans_scene(imacity::FreeflyCamera &camera){
    for(int i = 1; i<m_nb_scenes; i++){
        if (m_afficher_scene[i])
            est_dans_scene(camera, i);
    }
}

void GamePlay::verifie_zone_cle(const imacity::FreeflyCamera &camera){
    m_peut_ramasser = false;
    if (est_dans_zone(camera, std::stof(m_File_Description_Zones.getString("zone_cle1.x")),
                      std::stof(m_File_Description_Zones.getString("zone_cle1.z")),
                      std::stof(m_File_Description_Zones.getString("zone_cle1.r")))){
        m_peut_ramasser = true;
    }
}

void GamePlay::verifications_zones(imacity::FreeflyCamera &camera){
    verifie_zones_portes(camera);
    verifie_zone_cle(camera);
    reste_dans_scene(camera);
}
////END-------------CHECK AREAS-------------------------------------

////SCENE HANDLING----------------------------------------------------
//scene rendering according to the scene to be displayed
void GamePlay::drawScene(const glm::mat4 &projection, const glm::mat4 &view ){
    for (size_t i = 0; i<m_nb_scenes; i++){
        if (m_afficher_scene[i])
            m_scenes[i]->renderScene(projection, view);
    }

}

//scene loading
void GamePlay::loadScenes (){
    for (size_t i = 0; i<m_nb_scenes; i++){
        m_scenes[i] -> loadScene();
    }
}

//allows scene change
void GamePlay::changement_scene(const int numero_scene, imacity::FreeflyCamera &camera){
    assert (numero_scene <m_nb_scenes && numero_scene >=0 && "Numero de scene incorrect");
    for (size_t i = 0; i< m_nb_scenes; i++){
        m_afficher_scene[i] = false;
        m_peut_entrer_scene[i] = false;
    }
    m_afficher_scene[numero_scene] = true;
    this->set_camera_new_scene(camera, numero_scene);
    m_check_scene_limite = true;
}

void GamePlay::set_camera_new_scene(imacity::FreeflyCamera &camera,const int i){
    assert (i <m_nb_scenes && i >=0 && "Numero de scene incorrect");
    camera.set_Position(std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".x")),
                        0.0,
                        std::stof(m_File_Description_Zones.getString("zone_scene" +  std::to_string(i) + ".z")));
}
////END------------SCENE HANDLING----------------------------------------------------

////KEY HANDLING----------------------------------------------------
//check if the key has been picked up
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

//get the key and disable its display in its scene
void GamePlay::recupere_cle(const int i){
    m_cles["cle"+std::to_string(i)] = true;
    m_scenes[i]->set_afficher_cle(false);
}
////END------KEY HANDLING----------------------------------------------------

////EVENTS---------------------------------------------------
void GamePlay::evenement_ramassage_de_cle(){
    if (m_afficher_scene[0]){
        //scene 1 is the only scene which has a specific aria to pick the key
        if(m_peut_ramasser)
            recupere_cle(0);
    }
    for(size_t i = 1; i<4; i++) {
        if (m_afficher_scene[i])
            recupere_cle(i);
    }
}

void GamePlay::evemement_entrer_porte(imacity::FreeflyCamera &camera){
    if (m_afficher_scene[1] ||
        m_afficher_scene[2] ||
        m_afficher_scene[3]) {
        changement_scene(0,camera);
    }else {
        for (int i = 0; i < m_nb_scenes; i++) {
            if (m_peut_entrer_scene[i]) {
                if (possede_cle(i)){
                    if (m_afficher_scene[0]) {
                        if (i == 0)
                            fin_jeu();
                        else
                            changement_scene(i,camera);
                    }
                }else{
                          std::cout << "Vous n'avez pas la clé, il faut la chercher !"<< std::endl;
                }
            }
        }
    }
}
////END--------EVENTS----------------------------------------------------

void GamePlay::fin_jeu(){
    std::cout << "Vous avez réussi à entrer dans le chateau !! " << std::endl;
    m_afficher_scene[0] = false;
}