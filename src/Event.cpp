#include "Event.hpp"
#include <iostream>

Event::Event() :m_key_mouve_A(false),
                m_key_mouve_D (false),
                m_key_mouve_S(false),
                m_key_mouve_W(false),
                m_canMove(true),
                m_canGet(true),
                m_speed(0.2){};

Event::~Event(){};


void Event::processInput(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game){
    //close window
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    deplacement(window, camera, game);
    interaction(window, camera, game);
    releve_touche(window);
}

void Event::releve_touche(GLFWwindow *window){
    //management of keystroke readings to avoid inertia effects
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE)
        m_canMove = true;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
        m_canGet = true;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
        m_key_mouve_A = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
        m_key_mouve_W = false;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
        m_key_mouve_D = false;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
        m_key_mouve_S = false;
}

void Event::deplacement(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game){
    if (game.get_check_scene_limite()) { //the movement in each scene can only be done within a certain radius
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            m_key_mouve_W = true;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            m_key_mouve_S = true;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            m_key_mouve_A = true;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            m_key_mouve_D = true;

        //the use of a boolean prevents a new input as long as the key is not pressed
        if (m_key_mouve_W)
            camera.moveFront(m_speed);
        if (m_key_mouve_D)
            camera.moveLeft(-m_speed / 60);
        if (m_key_mouve_A)
            camera.moveLeft(m_speed / 60);
        if (m_key_mouve_S)
            camera.moveFront(-m_speed);
    }
}

void Event::interaction(GLFWwindow *window, imacity::FreeflyCamera &camera, GamePlay &game){
    //event enter a house
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        if (m_canMove) {
            m_canMove = false;
            game.evemement_entrer_porte(camera);
        }
    }

    //event pick up a key
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
        if (m_canGet) {
            m_canGet = false;
            game.evenement_ramassage_de_cle();
        }
    }
}