#include <cmath>
#include <iostream>
#include <glimac/FreeflyCamera.hpp>

namespace glimac {

void FreeflyCamera::computeDirectionVectors(){
        float Phi = glm::radians(this->m_fPhi); 
        float Theta = glm::radians(this->m_fTheta);
        float PhiPlusPiSur2 = glm::radians(this->m_fPhi) + M_PI/2.;
        
        this->m_FrontVector = glm::vec3 (cos(Theta)*sin(Phi), sin(Theta),cos(Theta)*cos(Phi));
        this->m_LeftVector = glm::vec3 (sin(PhiPlusPiSur2), 0., cos(PhiPlusPiSur2));
        this->m_UpVector = glm::vec3 (glm::cross(this->m_FrontVector, this->m_LeftVector)); //produit vectoriel de F et L
} 

void FreeflyCamera::moveLeft(float t){
        this-> m_fPosition+= t* this-> m_LeftVector;
}

void FreeflyCamera::moveFront(float t){
        this-> m_fPosition+= t* this-> m_FrontVector;
}

void FreeflyCamera::rotateLeft(float degrees){
        this-> m_fPhi += degrees;
        this->computeDirectionVectors();
}

void FreeflyCamera::rotateUp (float degrees){
        this-> m_fTheta +=degrees;
        this->computeDirectionVectors();
}

glm::mat4 FreeflyCamera::getViewMatrix(){
        std::cout<< (this->m_FrontVector).x << " "<<(this->m_FrontVector).y << " "<< (this->m_FrontVector).z  << std::endl;
        return (glm::lookAt(this->m_fPosition, this-> m_fPosition + this->m_FrontVector, this->m_UpVector));
        
}


FreeflyCamera::~FreeflyCamera() {}

}