#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "FreeflyCamera.hpp"
#include "Model.hpp"
#include "Event.hpp"
#include "GamePlay.hpp"

#include <iostream>
#include <cmath>


void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
imacity::FreeflyCamera camera;
float lastX = SCR_WIDTH / 2.0f;
bool firstMouse = true;

GamePlay Game;

int main(){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Imacity", NULL, NULL);
    try {
        if (window == NULL)
            throw std::string("Failed to create GLFW window");
    }catch (const std::string &err){
        std::cout << "Error"<< err << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, mouse_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    // tell stb_image.h to flip loaded texture's on the y-axis (before loading model).
    stbi_set_flip_vertically_on_load(true);

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile shaders
    // -------------------------

    Shader modelShader("shaders/modelLoading.vs.glsl", "shaders/modelLoading.fs.glsl");
    Shader lightingShader("shaders/lightning.vs.glsl", "shaders/lightning.fs.glsl");

    lightingShader.use();

    lightingShader.setInt("material.diffuse", 0);
    lightingShader.setInt("material.specular", 1);


    // render loop
    // -----------
    static const float speed = 1;
    
    Event makeMove;
    Game.loadScenes();

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)){
        //gameplay
        // ----
        Game.verifications_zones(camera);

        // input
        // -----
        makeMove.processInput(window, camera, Game);

        // render
        // ------
        glClearColor(0.1f, 0.7f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // positions of the point lights
        glm::vec3 pointLightPositions[] = {
            glm::vec3( 0.7f,  0.2f,  2.0f),
            glm::vec3( 2.3f, -3.3f, -4.0f),
            glm::vec3(-4.0f,  2.0f, -12.0f),
            glm::vec3( 0.0f,  0.0f, -3.0f)
        };

        //modelShader.use();
        lightingShader.use();
        lightingShader.setInt("material.diffuse", 0.2);
        lightingShader.setInt("material.specular", 1.);


        /// directional light
        lightingShader.setVec3("dirLight.direction", 0.5f, -0.5f, -0.5f);
        lightingShader.setVec3("dirLight.ambient", (float)sin(0.1*glfwGetTime())*glm::vec3(0.7f, 0.2f, 0.5f));
        lightingShader.setVec3("dirLight.diffuse", 0.7f, 0.4f, 0.4f);
        lightingShader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
        // point light 1
        /*lightingShader->setVec3("pointLights[0].position", glm::vec3(std::stof(m_IniFile.getString("light.position_x")),
                                                                    std::stof(m_IniFile.getString("light.position_y")),
                                                                    std::stof(m_IniFile.getString("light.position_z"))
                                ));
        lightingShader->setVec3("pointLights[0].ambient", glm::vec3(std::stof(m_IniFile.getString("light.ambient_r")),
                                                                    std::stof(m_IniFile.getString("light.ambient_g")),
                                                                    std::stof(m_IniFile.getString("light.ambient_b"))
                                ));
        lightingShader->setVec3("pointLights[0].diffuse", glm::vec3(std::stof(m_IniFile.getString("light.diffuse_r")),
                                                                    std::stof(m_IniFile.getString("light.diffuse_g")),
                                                                    std::stof(m_IniFile.getString("light.diffuse_b"))
                                ));
        lightingShader->setVec3("pointLights[0].specular", glm::vec3(std::stof(m_IniFile.getString("light.specular_r")),
                                                                    std::stof(m_IniFile.getString("light.specular_g")),
                                                                    std::stof(m_IniFile.getString("light.specular_b"))
                                ));
        lightingShader->setFloat("pointLights[0].constant", std::stof(m_IniFile.getString("light.constant")));
        lightingShader->setFloat("pointLights[0].linear", std::stof(m_IniFile.getString("light.linear")));
        lightingShader->setFloat("pointLights[0].quadratic", std::stof(m_IniFile.getString("light.quadratic")));*/
        // point light 1
        lightingShader.setVec3("pointLights[0].position", pointLightPositions[0]);
        lightingShader.setVec3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[0].constant", 1.0f);
        lightingShader.setFloat("pointLights[0].linear", 0.09);
        // point light 2
        lightingShader.setVec3("pointLights[1].position", pointLightPositions[1]);
        lightingShader.setVec3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[1].constant", 1.0f);
        lightingShader.setFloat("pointLights[1].linear", 0.09);
        lightingShader.setFloat("pointLights[1].quadratic", 0.032);
        // point light 3
        lightingShader.setVec3("pointLights[2].position", pointLightPositions[2]);
        lightingShader.setVec3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[2].constant", 1.0f);
        lightingShader.setFloat("pointLights[2].linear", 0.09);
        lightingShader.setFloat("pointLights[2].quadratic", 0.032);
        // point light 4
        lightingShader.setVec3("pointLights[3].position", pointLightPositions[3]);
        lightingShader.setVec3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
        lightingShader.setVec3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
        lightingShader.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("pointLights[3].constant", 1.0f);
        lightingShader.setFloat("pointLights[3].linear", 0.09);
        lightingShader.setFloat("pointLights[3].quadratic", 0.032);
        // spotLight
        lightingShader.setVec3("spotLight.position", camera.get_Position());
        lightingShader.setVec3("spotLight.direction", camera.m_FrontVector);
        lightingShader.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
        lightingShader.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
        lightingShader.setFloat("spotLight.constant", 1.0f);
        lightingShader.setFloat("spotLight.linear", 0.09);
        lightingShader.setFloat("spotLight.quadratic", 0.032);
        lightingShader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
        lightingShader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));  
        


        glm::mat4 projection = glm::perspective(glm::radians(70.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();


        modelShader.setMat4("projection", projection);
        modelShader.setMat4("view", view);

        lightingShader.setMat4("projection", projection);
        lightingShader.setMat4("view", view);

        Game.drawScene(projection, view);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    if (firstMouse) {
        lastX = xpos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    lastX = xpos;

    glfwGetCursorPos(window, &xpos, &ypos);
    camera.rotateLeft((xoffset)/60.f);
}

