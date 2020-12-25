#include <iostream>

#include "Item.hpp"

void Item::get() {
    //si click sur objet = true
    //count ++
    //this.id = count
}


void Item::display() {
    if (this->count == 0) {
        std::cout << "Aucun item à afficher" << std::endl;
        return;
    }

    for (unsigned int i = 0; i < this->count; i++) {
        //afficher en haut à droite les images
    }
};


void Item::use() {
    //si on clique sur une porte utilisée automatiquement
    //on passe à une autre scène
};