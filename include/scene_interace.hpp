#ifndef SCENE_INTERFACE_HEADERGUARD
#define SCENE_INTERFACE_HEADERGUARD

#include <string>
#include <vector>

namespace renmo {
    class SceneInterface {
        public:
            SceneInterface(std::string name,
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

    class TestScene:public SceneInterface {
        public:
            TestScene(std::string name,
                std::string desc,
                std::vector<std::string> settings) :
                SceneInterface( name, desc, settings)    
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