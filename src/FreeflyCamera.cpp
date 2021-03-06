#include <cmath>
#include "FreeflyCamera.hpp"

namespace imacity {
    void FreeflyCamera::computeDirectionVectors() {
        float Phi = glm::radians(this->m_fPhi);
        float Theta = glm::radians(this->m_fTheta);
        float PhiPlusPiSur2 = glm::radians(this->m_fPhi) + M_PI / 2.;

        this->m_FrontVector = glm::vec3(cos(Theta) * sin(Phi), sin(Theta), cos(Theta) * cos(Phi));
        this->m_LeftVector = glm::vec3(sin(PhiPlusPiSur2), 0., cos(PhiPlusPiSur2));
        this->m_UpVector = glm::vec3(glm::cross(this->m_FrontVector, this->m_LeftVector)); //produit vectoriel de F et L
    }

    glm::vec3 FreeflyCamera::get_Position() const {
        return m_fPosition;
    }

    void FreeflyCamera::set_Position(const float &x, const float &y, const float &z) {
        m_fPosition.x = x;
        m_fPosition.y = y;
        m_fPosition.z = z;
    }

    void FreeflyCamera::moveLeft(float t) {
        this->m_fPosition += t * this->m_LeftVector;
    }

    void FreeflyCamera::moveFront(float t) {
        this->m_fPosition += t * this->m_FrontVector;
    }

    void FreeflyCamera::rotateLeft(float degrees) {
        this->m_fPhi += degrees;
        this->computeDirectionVectors();
    }

    void FreeflyCamera::rotateUp(float degrees) {
        this->m_fTheta += degrees;
        this->computeDirectionVectors();
    }

    glm::mat4 FreeflyCamera::getViewMatrix() {
        return (glm::lookAt(this->m_fPosition, this->m_fPosition + this->m_FrontVector, this->m_UpVector));

    }

    FreeflyCamera::~FreeflyCamera() {}
}