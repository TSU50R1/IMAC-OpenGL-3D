#include "Event.hpp"
#include <iostream>

Event::Event(FreeflyCamera _camera){
  this->m_camera = _camera;
}
Event::~Event(){};

void Event::processInput(GLFWwindow *window, float t){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
      m_camera.moveFront(t);
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
      m_camera.moveFront(-t);
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
      m_camera.moveLeft(t/60);
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
      m_camera.moveLeft(-t/60);
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
      m_camera.rotateLeft(t);
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
      m_camera.rotateLeft(-t);
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
      m_camera.rotateUp(t);
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
      m_camera.rotateUp(-t);
}