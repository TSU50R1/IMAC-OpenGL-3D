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


void Event::processInput(GLFWwindow *window, FreeflyCamera &camera, GamePlay &game){


        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        //le mouvement dans chaque scene ne peut se faire que dans un certain rayon
        if (game.get_check_scene_limite()) {
            if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
                m_key_mouve_W = true;
            if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
                m_key_mouve_S = true;
            if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
                m_key_mouve_A = true;
            if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
                m_key_mouve_D = true;

            if (m_key_mouve_W)
                camera.moveFront(m_speed);
            if (m_key_mouve_D)
                camera.moveLeft(-m_speed / 60);
            if (m_key_mouve_A)
                camera.moveLeft(m_speed / 60);
            if (m_key_mouve_S)
                camera.moveFront(-m_speed);
        }


    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        if (m_canMove) {
            m_canMove = false;
            if (game.get_bool_scene(1) ||
                game.get_bool_scene(2) ||
                game.get_bool_scene(3)) {
                //camera.set_Position(0.0f, 0.0f, 0.0f);
                game.changement_scene(0,camera);
            }else {
                for (int i = 0; i < game.get_nb_scene(); i++) {
                    if (game.get_bool_peut_entrer(i)) {
                       // if (game.possede_cle(i)){
                            if (game.get_bool_scene(0)) {
                                if (i == 0){
                                    game.fin_jeu();
                                } else {
                                    game.changement_scene(i,camera);
                                }
                            }
                       // }else{
                      //      std::cout << "Vous n'avez pas la clé, il faut la chercher !"<< std::endl;
                      //  }
                    }
                }
            }
        }
    }

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
       if (m_canGet) {
            m_canGet = false;
            if (game.get_bool_scene(0)){
                if(game.get_bool_peut_ramasser()){
                    game.recupere_cle(0);
                }
            }
            for(size_t i = 1; i<4; i++) {
                if (game.get_bool_scene(i)) {
                    game.recupere_cle(i);
                }
            }
        }
    }

    //gestion des relevé de touche pour éviter les effets d'inertie
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE)
        m_canMove = true;
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_RELEASE)
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


