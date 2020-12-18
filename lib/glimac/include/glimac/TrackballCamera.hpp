#pragma once

#include <vector>
#include "common.hpp"

namespace glimac {

class TrackballCamera {
    private :
        float m_fDistance; // distance par rapport au centre de la scène
        float m_fAngleX; // angle effectué par la caméra autpur de l'axe x de la scène (rotation vers le haut ou ver le bas)
        float m_fAngleY; // angle effectué par la caméra autour de l'axe y de la scène (ves la droite ou la gauche)

    public :

        TrackballCamera():
        m_fDistance(5.),  m_fAngleX (0.), m_fAngleY(0.)
        {}

        ~TrackballCamera();

        void moveFront(float delta); //permet d'avancer/reculer la caméra.
        //si delta positif la caméra avance si non elle recule
        void rotateLeft(float degrees); // permet de tourner latéralement autour du centre de vision
        void rotateUp(float degrees); //permet de tourner verticalement autour du centre de vision
        glm::mat4 getViewMatrix() const;
};
    
}