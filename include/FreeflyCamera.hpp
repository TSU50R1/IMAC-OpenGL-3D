#pragma once

#include <vector>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace imacity {
    class FreeflyCamera {
    private :
        float m_fPhi; // données sphériques du vecteur F
        float m_fTheta;
        glm::vec3 m_LeftVector;
        glm::vec3 m_UpVector;
        glm::vec3 m_fPosition; // position de le caméra

        void computeDirectionVectors();

    public :

        glm::vec3 m_FrontVector;

        void set_Position (const float &x, const float &y, const float &z);
        glm::vec3 get_Position  () const;

        glm::vec3 get_Position() const;

        FreeflyCamera() :
                m_fPosition(glm::vec3(0., 0., 0.)), m_fPhi(180), m_fTheta(0.) {
            computeDirectionVectors();
        }

        ~FreeflyCamera();

        void moveLeft(float t);

        void moveFront(float t);

        void rotateLeft(float degrees);

        void rotateUp(float degrees);


        glm::mat4 getViewMatrix();
    };
}
