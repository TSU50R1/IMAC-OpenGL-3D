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
    void processInput(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game);
    void deplacement(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game);
    void interaction(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game);
    void releve_touche(GLFWwindow *window);
};