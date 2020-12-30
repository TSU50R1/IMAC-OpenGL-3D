<<<<<<< HEAD
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FreeflyCamera.hpp"

class Event {
public:
  FreeflyCamera &m_camera;
public:
    Event(FreeflyCamera &_camera);
    ~Event();
    void processInput(GLFWwindow *window, float t);
};
=======
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FreeflyCamera.hpp"
#include "Interaction.hpp"

class Event {

private:
    int m_id;
    const float m_speed;
    bool m_key_mouve_S;
    bool m_key_mouve_A;
    bool m_key_mouve_W;
    bool m_key_mouve_D;


public:
    Event();
    ~Event();
    void processInput(GLFWwindow *window,FreeflyCamera &camera, bool &drawscene1, bool &drawscene2, bool &canMove);
};
>>>>>>> origin/Laurine
