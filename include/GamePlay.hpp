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
    bool m_ramasser_cle;
    bool m_check_zone;

    std::vector <bool> m_afficher_scene;
    std::vector <bool> m_peut_entrer_scene;
    std::vector <Scene*> m_scenes;
    std::map <std::string, bool> m_cles;

    IniLoadMap m_File_Description_Zones;
    size_t m_nb_zones_portes;
    size_t m_nb_zones_cle;

public:
    GamePlay();

    ~GamePlay();

    bool est_dans_zone(const FreeflyCamera &camera, float x_zone, float z_zone,  float R);
    void drawScene(const glm::mat4 &projection, const glm::mat4 &view );
    void loadScenes ();
    bool possede_cle (const int i);
    void verifie_zones_portes(const FreeflyCamera &camera);
    void changement_scene(const int numero_scene);



    inline bool get_bool_scene(const int i) const {return m_afficher_scene[i];}
    inline void set_bool_scene(const bool afficher, const int i){ m_afficher_scene[i] = afficher;}
    inline bool get_bool_peut_entrer(const int i) const {return m_peut_entrer_scene[i];}
    inline int get_nb_scene() const {return m_nb_scenes;}
};
