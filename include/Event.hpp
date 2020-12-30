#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FreeflyCamera.hpp"
#include "Item.hpp"

class Event {
public:
  FreeflyCamera &m_camera;
public:
    Event(FreeflyCamera &_camera);
    ~Event();
    void processInput(GLFWwindow *window, float t);
 	void interact(GLFWwindow *window, Item &item);
};