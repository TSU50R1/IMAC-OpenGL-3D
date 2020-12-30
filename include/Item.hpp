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

class Item {

public:
    FreeflyCamera &m_camera;
    Item(FreeflyCamera &_camera);
    ~Item(); 
    void get();
    void display();
    void use();

private:
    Model* model;
    int count;
    int id;
    Scene* scene;
    struct Door {
    	int id;
		float pos_x;
		float pos_y;
    };
    Door door;
    struct Zone {
    	int id;
		float pos_x;
		float pos_y;
    };
    Zone zone;
};
