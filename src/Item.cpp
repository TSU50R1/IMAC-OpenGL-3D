#include <iostream>
#include <string>

#include "Item.hpp"

Item::Item(FreeflyCamera &_camera) : m_camera(_camera){}
Item::~Item(){};


void Item::display() {
    if (this->count == 0) {
        std::cout << "Aucun item à afficher" << std::endl;
        return;
    }

    for (unsigned int i = 0; i < this->count; i++) {
        //afficher en haut à droite les images
    }
}

void Item::get() {
    if (this->zone.pos_x == this->m_camera.m_fPosition.x && this->zone.pos_y == this->m_camera.m_fPosition.y) //faire si (position caméra = position de la zone)
    {
        this-> count ++;
        this-> id = this->zone.id;
        this->display();
    }
    std::cout << "aucun item ici" << std::endl;
}


void Item::use() {
    if (this->door.id == this->id) {
        Scene scene ("ini_files/" + std::to_string(this->door.id) + ".conf");
        scene.loadScene();
    }
    std::cout << "Impossible d'utiliser l'item ici" << std::endl;
}