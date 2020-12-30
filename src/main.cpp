#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "myShader.hpp"
#include "FreeflyCamera.hpp"
#include "Model.hpp"
#include "LoadINI.hpp"
#include "Scene.hpp"
#include "Event.hpp"
<<<<<<< HEAD

#include <iostream>
#include <string>
=======
#include "Interaction.hpp"

#include <iostream>
#include <string>
#include <cmath>
>>>>>>> origin/Laurine


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
<<<<<<< HEAD
//void processInput(GLFWwindow *window, float t);
=======
void processInput(GLFWwindow *window, float t);
>>>>>>> origin/Laurine

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
FreeflyCamera camera;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

<<<<<<< HEAD
=======
Event makeMove;
//Interaction item(camera);


bool drawscene1 = true;
bool drawscene2 = false;
bool canMove = true;

>>>>>>> origin/Laurine
// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

<<<<<<< HEAD
int main(){
    Scene scene ("ini_files/Scene1.conf");

    IniLoadMap myINIFile;
    myINIFile.mapPath("ini_files/Scene1.conf");
=======
bool est_dans_zone(const FreeflyCamera &camera, float x_zone, float z_zone,  float R){
    if (sqrt(pow(x_zone-camera.get_Position().x,2)+pow(z_zone-camera.get_Position().z,2))<=R){
        std::cout << "Est dans la zone" << std:: endl;
        return true;
    }else{
        return false;
    }
}

int main(){
    Scene scene1 ("ini_files/Scene1.conf");
    Scene scene2 ("ini_files/Scene2.conf");
>>>>>>> origin/Laurine


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
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

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

<<<<<<< HEAD
    scene.loadScene();

    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    Event event (camera);
    static const float speed = 0.4;
    while (!glfwWindowShouldClose(window)){
=======
    // build and compile shaders
    // -------------------------
    Shader ourShader1("shaders/modelLoading.vs.glsl", "shaders/modelLoading.fs.glsl");
    Shader lightingShader("shaders/lightning.vs.glsl", "shaders/lightning.fs.glsl");


    scene1.loadScene();
    scene2.loadScene();
    // load models
    // -----------



    // render loop
    // -----------
    bool dans_zone;
    while (!glfwWindowShouldClose(window)){
        float R = 1.;
        float x_zone = -8.15;
        float z_zone = 2.50;
        est_dans_zone(camera, x_zone, z_zone, R);

        std::cout << camera.get_Position().x << " " <<camera.get_Position().y << " " <<camera.get_Position().z    << std::endl;
>>>>>>> origin/Laurine
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
<<<<<<< HEAD
        event.processInput(window, speed);

=======
        makeMove.processInput(window, camera,  drawscene1, drawscene2,canMove);
>>>>>>> origin/Laurine
        // render
        // ------
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

<<<<<<< HEAD
        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(70.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();

        scene.renderScene(projection, view);
=======
        // don't forget to enable shader before setting uniforms

        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);

        glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(70.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 model = glm::mat4(1.);


        //lightingShader.setMat4("model", glm::mat4(0.));
        //lightingShader.setVec4("ambiant_color", glm::vec4(0.4, 0.4, 0.4, 1.0));
        //lightingShader.setVec4("light_position", glm::vec4(1.0, 1.0, 1.0, 1.0));
        //lightingShader.setMat4("matrixpmv", projection * view * model);

        if (drawscene1 == true)
            scene1.renderScene(projection, view);
        if (drawscene2 == true)
            scene2.renderScene(projection, view);
>>>>>>> origin/Laurine


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

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------

<<<<<<< HEAD
=======
/*void processInput(GLFWwindow *window, float t){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
    {
      // call camera to move FORWARD
      camera.moveFront(t);
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
    {
      // call camera to move BACKWARD
      camera.moveFront(-t);
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
      // call camera to move LEFT
      camera.moveLeft(t/60);
    }
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
    {
      // call camera to move RIGHT
      camera.moveLeft(-t/60);
    }
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
      // call camera to ROTATE LEFT
      camera.rotateLeft(t);
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
      // call camera to ROTATE RIGHT
      camera.rotateLeft(-t);
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
      // call camera to move ROTATE UP
      camera.rotateUp(t);
    }
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
      // call camera to move ROTATE DOWN
      camera.rotateUp(-t);
    }
}*/

>>>>>>> origin/Laurine
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
<<<<<<< HEAD
    if (firstMouse){
=======
    if (firstMouse) {
>>>>>>> origin/Laurine
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
<<<<<<< HEAD
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

   // camera.ProcessMouseMovement(xoffset, yoffset);
=======
    lastX = xpos;
    lastY = ypos;

    glfwGetCursorPos(window, &xpos, &ypos);
    camera.rotateLeft((xoffset)/60.f);

    //camera.rotateUp((mousePositionY - ypos)/60.f);
>>>>>>> origin/Laurine
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    //camera.ProcessMouseScroll(yoffset);
}
