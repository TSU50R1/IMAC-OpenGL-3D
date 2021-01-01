#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FreeflyCamera.hpp"
#include "GamePlay.hpp"

class Event {

private:
    int m_id;
    const float m_speed;
    bool m_key_mouve_S;
    bool m_key_mouve_A;
    bool m_key_mouve_W;
    bool m_key_mouve_D;
    bool m_canMove;
    bool m_canGet;


public:
    Event();
    ~Event();
    void processInput(GLFWwindow *window, FreeflyCamera &camera, GamePlay &game);
    void mouse_callback(GLFWwindow* window, FreeflyCamera &camera, double xpos, double ypos);
};