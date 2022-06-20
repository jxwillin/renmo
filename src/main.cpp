//#define DEBUG_PRINT_MACROS
#ifdef DEBUG_PRINT_MACROS
#define MACRO_DEBUG_PRINT std::cout<<__FILE__<<"::"<<__LINE__<<std::endl;  
#else
#define MACRO_DEBUG_PRINT
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <memory>
#include <renmo.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    MACRO_DEBUG_PRINT

    std::unique_ptr<renmo::Context> gl_context = std::make_unique<renmo::Context>();
    std::unique_ptr<renmo::Window> gl_window = std::make_unique<renmo::Window>(SCR_WIDTH,SCR_HEIGHT);
    gl_window->make_current_context();
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    gl_window->setup_imgui();
    ImGui_ImplOpenGL3_Init("#version 100");

    MACRO_DEBUG_PRINT
    while (gl_window->should_close())
    {
        MACRO_DEBUG_PRINT
        gl_window->process_input();

        gl_window->clear_colour(0.2f, 0.3f, 0.3f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        bool show_demo_window = true;
        ImGui::ShowDemoWindow(&show_demo_window);
        ImGui::Render();
        int display_w, display_h;
        gl_window->get_display_size(&display_w, &display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        gl_window->swap_buffers();
        gl_context->poll_events();
        MACRO_DEBUG_PRINT
    }
    return 0;
}




