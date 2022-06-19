#ifndef WINDOW_HEADERGUARD
#define WINDOW_HEADERGUARD

struct GLFWwindow;

namespace renmo {
    namespace utilities {
        
    }

    class Window {
        public:
            Window(unsigned int SCR_WIDTH, unsigned int SCR_HEIGHT);
            void make_current_context();
            void set_framebuffer_size_change_callback();
            bool should_close();
            void swap_buffers();
            void process_input();
            void clear_colour(float r, float g, float b);

        private:
            GLFWwindow* glfw_window;
    };
}

#endif //WINDOW_HEADERGUARD