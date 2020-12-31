#include "Event.hpp"
#include <iostream>

Event::Event() :m_key_mouve_A(false),
                m_key_mouve_D (false),
                m_key_mouve_S(false),
                m_key_mouve_W(false),
                m_canMove(true),
                m_speed(0.2){};

Event::~Event(){};


void Event::processInput(GLFWwindow *window, FreeflyCamera &camera, GamePlay &game){

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            m_key_mouve_W=true;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            m_key_mouve_S=true;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            m_key_mouve_A=true;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            m_key_mouve_D=true;

        if (m_key_mouve_W)
            camera.moveFront(m_speed);
        if (m_key_mouve_D)
            camera.moveLeft(-m_speed / 60);
        if (m_key_mouve_A)
            camera.moveLeft(m_speed / 60);
        if (m_key_mouve_S)
            camera.moveFront(-m_speed);


    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        if (m_canMove) {
            m_canMove = false;
            if (game.get_bool_scene(1) == true ||
                game.get_bool_scene(2) == true ||
                game.get_bool_scene(3) == true) {
                camera.set_Position(0.0f, 0.0f, 0.0f);
                game.changement_scene(0);
            }else {
                for (int i = 0; i < game.get_nb_scene(); i++) {
                    if (game.get_bool_peut_entrer(i)) {
                        if (game.get_bool_scene(0) == true) {
                            camera.set_Position(0.3045f, 0.0f, -58.7628f);
                            game.changement_scene(i);
                        }
                    }
                }
            }
        }
    }

    //gestion des relevé de touche pour éviter les effets d'inertie
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE)
        m_canMove = true;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
        m_key_mouve_A = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
        m_key_mouve_W = false;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
        m_key_mouve_D = false;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
        m_key_mouve_S = false;
}

/*
// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void Event::mouse_callback(GLFWwindow* window, FreeflyCamera &camera, double xpos, double ypos){
    if (m_firstMouse) {
        m_lastX = xpos;
        m_lastY = ypos;
        m_firstMouse = false;
    }

    float xoffset = xpos - m_lastX;
    m_lastX = xpos;
    m_lastY = ypos;

    glfwGetCursorPos(window, &xpos, &ypos);
    camera.rotateLeft((xoffset)/60.f);

}
*/


