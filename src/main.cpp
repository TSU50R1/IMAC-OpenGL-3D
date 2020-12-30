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
#include "Item.hpp"

#include <iostream>
#include <string>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window, float t);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
FreeflyCamera camera;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

Event makeMove(camera);
Item item(camera);


// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main(){
    Scene scene ("ini_files/Scene1.conf");

    IniLoadMap myINIFile;
    myINIFile.mapPath("ini_files/Scene1.conf");


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

    // build and compile shaders
    // -------------------------
    Shader ourShader1("shaders/modelLoading.vs.glsl", "shaders/modelLoading.fs.glsl");
    Shader lightingShader("shaders/lightning.vs.glsl", "shaders/lightning.fs.glsl");


    scene.loadScene();
    // load models
    // -----------
    Model ourModel1(myINIFile.getString("model" +  std::to_string(1) + ".models_directory"));
    Model ourModel2(myINIFile.getString("model" +  std::to_string(1) + ".models_directory"));


    // draw in wireframe
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    static const float speed = 0.2;
    while (!glfwWindowShouldClose(window)){
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        makeMove.processInput(window, speed);
        // render
        // ------
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // don't forget to enable shader before setting uniforms

        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("lightColor",  1.0f, 1.0f, 1.0f);

        glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

        // view/projection transformations
        glm::mat4 projection = glm::perspective(glm::radians(70.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        glm::mat4 model = glm::mat4(1.);



        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f));

        //lightingShader.setMat4("model", glm::mat4(0.));
        //lightingShader.setVec4("ambiant_color", glm::vec4(0.4, 0.4, 0.4, 1.0));
        //lightingShader.setVec4("light_position", glm::vec4(1.0, 1.0, 1.0, 1.0));
        //lightingShader.setMat4("matrixpmv", projection * view * model);

        scene.renderScene(projection, view);


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
    if (firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

   // camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
    //camera.ProcessMouseScroll(yoffset);
}
