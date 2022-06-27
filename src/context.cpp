#include <context.hpp>

#include <iostream>

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

void renmo::Context::set_context(renmo::Window::unique_ptr &win) {
    glfwMakeContextCurrent(win->glfw_window);

    static bool run_once_flag = false;
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        //TODO:: throw exception
    }
    run_once_flag = true;
}
