#include <cmath>
#include <iostream>
#include <glimac/TrackballCamera.hpp>

namespace glimac {

void TrackballCamera::moveFront(float delta){
            this->m_fDistance += delta;
        
}

TrackballCamera::~TrackballCamera() {
    }
    
void TrackballCamera::rotateLeft(float degrees){
        this->m_fAngleY += degrees ;
} 

void TrackballCamera::rotateUp(float degrees){
        this->m_fAngleX += degrees ;
} 

glm::mat4 TrackballCamera::getViewMatrix() const{
        glm::mat4 Translation = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, 1, 0, 0),glm::vec4(0, 0, 1, 0) , glm::vec4(0 , 0, -this->m_fDistance , 1));
        glm::mat4 RotationX = glm::mat4(glm::vec4(cos(glm::radians(this->m_fAngleX)), 0, -sin(glm::radians(this->m_fAngleX)), 0), glm::vec4(0, 1, 0, 0),glm::vec4(sin(glm::radians(this->m_fAngleX)), 0, cos(glm::radians(this->m_fAngleX)), 0) , glm::vec4(0 , 0, 0 , 1));
        glm::mat4 RotationY = glm::mat4(glm::vec4(1, 0, 0, 0), glm::vec4(0, cos(glm::radians(this->m_fAngleY)), sin(glm::radians(this->m_fAngleY)), 0),glm::vec4(0, -sin(glm::radians(this->m_fAngleY)), cos(glm::radians(this->m_fAngleY)), 0) , glm::vec4(0 , 0, 0 , 1));;
        glm::mat4 ViewMatrix = Translation*RotationX*RotationY ;
        return (ViewMatrix);
}


}