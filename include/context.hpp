#ifndef CONTEXT_HEADERGUARD
#define CONTEXT_HEADERGUARD

namespace renmo {
    class Context {
        public:
            Context();
            ~Context();

            void poll_events();
        private:
            int x;
    };
}

#endif //CONTEXT_HEADERGUARD