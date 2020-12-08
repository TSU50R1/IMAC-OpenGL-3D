cmake_minimum_required(VERSION 3.0)
add_definitions(-std=c++11)

project(Imacity)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)


file(GLOB_RECURSE SRC_FILES src/*.cpp) ##ajoute tout les fichiers .cpp
file(GLOB_RECURSE HEADER_FILES include/*.hpp)
file(GLOB_RECURSE SHADER_FILES shaders/*.glsl)


find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

################################ Includes ######################################
include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIRS}
        lib/glimac/include
        lib/glm/include
)

add_subdirectory(lib/glimac)
set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${SHADER_FILES})
target_link_libraries(${PROJECT_NAME} ${ALL_LIBRARIES})

file(COPY src/shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


