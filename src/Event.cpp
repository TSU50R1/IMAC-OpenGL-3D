#include "Event.hpp"
#include <iostream>

Event::Event(FreeflyCamera &_camera) : m_camera(_camera){};
Event::~Event(){};

void Event::processInput(GLFWwindow *window, float t){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
      m_camera.moveFront(t);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
      m_camera.moveFront(-t);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
      m_camera.moveLeft(t/60);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
      m_camera.moveLeft(-t/60);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
      m_camera.rotateLeft(t);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
      m_camera.rotateLeft(-t);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
      m_camera.rotateUp(t);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
      m_camera.rotateUp(-t);
}

void Event::interact(GLFWwindow *window, Item &item){
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
      item.use();
      item.get();
    }
    std::cout << "aucune intéraction disponible" << std::endl;
}