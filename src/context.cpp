#include <context.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

renmo::Context::Context() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

renmo::Context::~Context() {
    glfwTerminate();
}

void renmo::Context::poll_events() {
    glfwPollEvents();
}
