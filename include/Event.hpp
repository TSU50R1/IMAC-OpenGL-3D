#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "FreeflyCamera.hpp"
#include "GamePlay.hpp"

class Event {

private:
    int m_id;
    const float m_speed;
    bool m_key_move_S;
    bool m_key_move_A;
    bool m_key_move_W;
    bool m_key_move_D;
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