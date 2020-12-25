#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include "stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Model.hpp"
#include "Scene.hpp"
#include "Event.hpp"

class Item {

public:
    
    Item(){}
    ~Item(){}    
    void get();
    void display();
    void use();

private:
    Model* model;
    int count;
    int id;
    Scene* scene;
};
