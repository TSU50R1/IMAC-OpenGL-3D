#include "Event.hpp"
#include <iostream>

Event::Event() :m_key_mouve_A(false),
                                                          m_key_mouve_D (false),
                                                          m_key_mouve_S(false),
                                                          m_key_mouve_W(false),
                                                          m_speed(0.2){};

Event::~Event(){};


void Event::processInput(GLFWwindow *window, FreeflyCamera &camera, bool &drawscene1, bool &drawscene2, bool &canMove){
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


    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS){
                if (canMove) {
                    canMove = false;
                    std::cout << "c a été pressé" << std::endl;
                    if (drawscene1 == true){
                        camera.set_Position ( 0.3045f, 0.0f, -58.7628);
                        std::cout << "coucou1" << std::endl;
                        drawscene1 = false;
                        drawscene2 = true;
                    }else{
                        camera.set_Position ( 0.0f, 0.0f, 0.0f);
                        std::cout << "coucou2" << std::endl;
                        drawscene1 = true;
                        drawscene2 = false;
                    }
                    std::cout << "drawscene1 " << drawscene1 << std::endl;
                    std::cout << "drawscene2 " << drawscene2 << std::endl;
                }

    }

    //gestion des relevé de touche pour éviter les effets d'inertie
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE)
        canMove = true;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
        m_key_mouve_A = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
        m_key_mouve_W = false;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
        m_key_mouve_D = false;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
        m_key_mouve_S = false;
}


