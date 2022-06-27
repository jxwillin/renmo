#include <window.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void framebuffer_size_callback(GLFWwindow* glfw_window, int width, int height);

renmo::Window::Window(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT) {
    glfw_window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (glfw_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        //TODO:: Throw exception
    }

    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback); 
}

bool renmo::Window::should_close() {
    return !glfwWindowShouldClose(glfw_window);
}

void renmo::Window::swap_buffers() {
    glfwSwapBuffers(glfw_window);
}

void renmo::Window::process_input() {
    if(glfwGetKey(glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(glfw_window, true);
}

void renmo::Window::set_framebuffer_size_change_callback() {
    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);
}

void renmo::Window::clear_colour(float r, float g, float b) {
    glClearColor( r, g, b, 1.0f);
}

void renmo::Window::setup_imgui() {
    ImGui_ImplGlfw_InitForOpenGL(glfw_window, true);
}

void renmo::Window::get_display_size(int *display_w, int *display_h) {
    glfwGetFramebufferSize(glfw_window, display_w, display_h);
}

void framebuffer_size_callback(GLFWwindow* glfw_window, int width, int height) {
    glViewport(0, 0, width, height);
}