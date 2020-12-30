#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "FreeflyCamera.hpp"
#include "Model.hpp"
#include "Scene.hpp"


class Interaction {
private:
    bool ramasser_cle;
    bool check_zone;

    bool affichage_scene1;
    bool affichage_scene2;
    bool affichage_scene3;
    bool affichage_scene4;

    Scene scene1;



public:
    FreeflyCamera &m_camera;
    Interaction(FreeflyCamera &_camera);
    ~Interaction();


};
