#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include <map>
#include <vector>

#include "FreeflyCamera.hpp"
#include "Model.hpp"
#include "Scene.hpp"
#include "LoadINI.hpp"


class GamePlay {
private:
    int m_nb_scenes;
    bool m_check_scene_limite;

    std::vector <bool> m_afficher_scene;
    std::vector <bool> m_peut_entrer_scene;
    bool m_peut_ramasser;
    std::vector <Scene*> m_scenes;


    IniLoadMap m_File_Description_Zones;
    size_t m_nb_zones_portes;
    std::map <std::string, bool> m_cles;

    //check zones
    void est_dans_scene(imacity::FreeflyCamera &camera, const int i);
    bool est_dans_zone(const imacity::FreeflyCamera &camera, float x_zone, float z_zone,  float R);
    void verifie_zone_cle(const imacity::FreeflyCamera &camera);
    void verifie_zones_portes(const imacity::FreeflyCamera &camera);

public:

    GamePlay();
    ~GamePlay();
    //scene handling
    void loadScenes ();
    void drawScene(const glm::mat4 &projection, const glm::mat4 &view, const imacity::FreeflyCamera &camera);
    void changement_scene(const int numero_scene,imacity::FreeflyCamera &camera);
    void set_camera_new_scene(imacity::FreeflyCamera &camera,const int i);
    void reste_dans_scene(imacity::FreeflyCamera &camera);
    void verifications_zones(imacity::FreeflyCamera &camera);
    //keys handling
    bool possede_cle (const int i);
    void recupere_cle(const int i);
    //event handling
    void evenement_ramassage_de_cle();
    void evemement_entrer_porte(imacity::FreeflyCamera &camera);
    //end if game
    void fin_jeu();


    inline bool get_check_scene_limite(){return m_check_scene_limite;}
};
