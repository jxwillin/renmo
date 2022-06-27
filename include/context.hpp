#ifndef CONTEXT_HEADERGUARD
#define CONTEXT_HEADERGUARD

#include <memory>
#include <window.hpp>

namespace renmo {
    class Context {
        public:
            Context();
            ~Context();
            void set_context(renmo::Window::unique_ptr &win);
            void poll_events();
            
        private:
            int x;
    };
}

#endif //CONTEXT_HEADERGUARD