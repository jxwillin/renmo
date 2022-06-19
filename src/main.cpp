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

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    MACRO_DEBUG_PRINT

    std::unique_ptr<renmo::Context> gl_context = std::make_unique<renmo::Context>();
    std::unique_ptr<renmo::Window> gl_window = std::make_unique<renmo::Window>(SCR_WIDTH,SCR_HEIGHT);
    gl_window->make_current_context();
    
    MACRO_DEBUG_PRINT
    while (gl_window->should_close())
    {
        MACRO_DEBUG_PRINT
        gl_window->process_input();

        gl_window->clear_colour(0.2f, 0.3f, 0.3f);
        glClear(GL_COLOR_BUFFER_BIT);

        gl_window->swap_buffers();
        gl_context->poll_events();
        MACRO_DEBUG_PRINT
    }
    return 0;
}




