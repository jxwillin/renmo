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
#include <renmo.hpp>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <string.h> //strcopy

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    MACRO_DEBUG_PRINT

    std::vector<std::unique_ptr<renmo::RendererInterface>> _renderers;
    _renderers.push_back(std::move(std::make_unique<renmo::TestRenderer>("A","a",std::vector<std::string>())));
    _renderers.push_back(std::move(std::make_unique<renmo::TestRenderer>("B","a\nb",std::vector<std::string>())));
    _renderers.push_back(std::move(std::make_unique<renmo::TestRenderer>("C","a\nb\nc",std::vector<std::string>())));
    _renderers.push_back(std::move(std::make_unique<renmo::TestRenderer>("D","a\nb\nc\nd",std::vector<std::string>())));

    std::vector<std::unique_ptr<renmo::SceneInterface>> _scenes;
    _scenes.push_back(std::move(std::make_unique<renmo::SceneInterface>("W","w",std::vector<std::string>())));
    _scenes.push_back(std::move(std::make_unique<renmo::SceneInterface>("X","w\nx",std::vector<std::string>())));
    _scenes.push_back(std::move(std::make_unique<renmo::SceneInterface>("Y","w\nx\ny",std::vector<std::string>())));
    _scenes.push_back(std::move(std::make_unique<renmo::SceneInterface>("Z","w\nx\ny\nz",std::vector<std::string>())));
    

    std::unique_ptr<renmo::Context> gl_context = std::make_unique<renmo::Context>();
    std::unique_ptr<renmo::Window> gl_window = std::make_unique<renmo::Window>(SCR_WIDTH,SCR_HEIGHT);
    gl_window->make_current_context();
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    gl_window->setup_imgui();
    ImGui_ImplOpenGL3_Init("#version 100");

    //Convert data into format IMGUI can use
    const char** _imgui_renderer_names = (const char**)malloc(_renderers.size()*sizeof(char*));
    const char** _imgui_renderer_descs = (const char**)malloc(_renderers.size()*sizeof(char*));
    {
        for(int i = 0; i < _renderers.size(); i++)
        {
            char* tmp = (char*)malloc(strlen(_renderers.at(i)->get_name().c_str()));
            strcpy(tmp, _renderers.at(i)->get_name().c_str());
            _imgui_renderer_names[i] = tmp;
        }
    
        for(int i = 0; i < _renderers.size(); i++)
        {
            char* tmp = (char*)malloc(strlen(_renderers.at(i)->get_desc().c_str()));
            strcpy(tmp, _renderers.at(i)->get_desc().c_str());
            _imgui_renderer_descs[i] = tmp;
        }
    }

    const char** _imgui_scene_names = (const char**)malloc(_scenes.size()*sizeof(char*));
    const char** _imgui_scene_descs = (const char**)malloc(_scenes.size()*sizeof(char*));
    {
        for(int i = 0; i < _scenes.size(); i++)
        {
            char* tmp = (char*)malloc(strlen(_scenes.at(i)->get_name().c_str()));
            strcpy(tmp, _scenes.at(i)->get_name().c_str());
            _imgui_scene_names[i] = tmp;
        }
    
        for(int i = 0; i < _scenes.size(); i++)
        {
            char* tmp = (char*)malloc(strlen(_scenes.at(i)->get_desc().c_str()));
            strcpy(tmp, _scenes.at(i)->get_desc().c_str());
            _imgui_scene_descs[i] = tmp;
        }
    }

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

        ImGui::Begin("Settings");

        static int scene_current = 0;
        ImGui::Combo("Scene", &scene_current, _imgui_scene_names, _scenes.size());
        if (ImGui::CollapsingHeader("Scene Description")) {
            ImGui::Text(_imgui_scene_descs[scene_current]);
        }

        static int renderer_current = 0;
        ImGui::Combo("Renderer", &renderer_current, _imgui_renderer_names, _renderers.size());
        if (ImGui::CollapsingHeader("Renderer Settings")) {
            ImGui::Text("Renderer settings");
        }
        if (ImGui::CollapsingHeader("Renderer Description")) {
            ImGui::Text(_imgui_renderer_descs[renderer_current]);
        }


        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        gl_window->get_display_size(&display_w, &display_h);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        gl_window->swap_buffers();
        gl_context->poll_events();
        MACRO_DEBUG_PRINT
    }

    //clean up C memory allocations
    {
        for(int i = 0; i < _renderers.size(); i++)
        {
            free((void*)_imgui_renderer_names[i]);
        }

        for(int i = 0; i < _renderers.size(); i++)
        {
            free((void*)_imgui_renderer_descs[i]);
        }

        for(int i = 0; i < _scenes.size(); i++)
        {
            free((void*)_imgui_scene_names[i]);
        }

        for(int i = 0; i < _scenes.size(); i++)
        {
            free((void*)_imgui_scene_descs[i]);
        }
    }

    return 0;
}




