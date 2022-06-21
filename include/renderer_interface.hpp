#ifndef RENDERER_INTERFACE_HEADERGUARD
#define RENDERER_INTERFACE_HEADERGUARD

#include <string>
#include <vector>

namespace renmo {
    class RendererInterface {
        public:
            RendererInterface(std::string name,
                std::string desc,
                std::vector<std::string> settings) :
                _name(name),
                _desc(desc),
                _settings(settings)    
            {

            }

            virtual std::string get_name() {
                return _name;
            }

            virtual std::string get_desc() {
                return _desc;
            }

            virtual std::vector<std::string> get_settings() {
                return _settings;
            }

        protected:
            std::string _name;
            std::string _desc;
            std::vector<std::string> _settings;
    };

    class TestRenderer:public RendererInterface {
        public:
            TestRenderer(std::string name,
                std::string desc,
                std::vector<std::string> settings) :
                RendererInterface( name, desc, settings)    
            {

            }

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