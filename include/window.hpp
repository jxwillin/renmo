#ifndef WINDOW_HEADERGUARD
#define WINDOW_HEADERGUARD

//#include <context.hpp>
#include <memory>

struct GLFWwindow;

namespace renmo {
    class Context;

    class Window {
        public:
            Window(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);
            void set_framebuffer_size_change_callback();
            bool should_close();
            void swap_buffers();
            void process_input();
            void clear_colour(float r, float g, float b);
            void setup_imgui();
            void get_display_size(int* display_w, int* display_h);

            typedef std::unique_ptr<renmo::Window> unique_ptr;
            
        private:
            GLFWwindow* glfw_window;

            friend class renmo::Context;
    };
}

#endif //WINDOW_HEADERGUARD