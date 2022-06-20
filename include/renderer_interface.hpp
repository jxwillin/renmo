#ifndef RENDERER_INTERFACE_HEADERGUARD
#define RENDERER_INTERFACE_HEADERGUARD

#include <string>
#include <vector>

namespace renmo {
    class RendererInterface {
        public:
            virtual std::string get_name() = 0;
            virtual std::string get_desc() = 0;
            virtual std::vector<std::string> get_settings() = 0;

        protected:
            std::string _name;
            std::string _desc;
            std::vector<std::string> _settings;
    };

    class TestRenderer:public RendererInterface {
        public:
            std::string get_name() {
                return _name;
            }

            std::string get_desc() {
                return _desc;
            }

            std::vector<std::string> get_settings() {
                return _settings;
            }
    };
}

#endif