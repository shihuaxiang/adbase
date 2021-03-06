#ifndef ADBASE_LUA_ENGINE_HPP_
#define ADBASE_LUA_ENGINE_HPP_

#include <adbase/Utility.hpp>
#include <functional>
#include <list>
#include "BindingUtils.hpp"

namespace adbase {
namespace lua {

class Engine : public adbase::Singleton<Engine>{
    protected:
        Engine();
        ~Engine();

    public:
        int addOnInit(std::function<void(lua_State *)> fn);
        int init(lua_State *state = nullptr);
        void addSearchPath(lua_State *L, const std::string &path, bool isFront);
        void addSearchPath(const std::string &path, bool isFront);
        bool runFile(const char* file);
        bool runFile(lua_State *L, const char* file);
        bool runCode(const char* codes);
        bool runCode(lua_State *L, const char* codes);
        lua_State* getLuaState();

    private:
        lua_State *_state;
        bool _ownerState;
        std::list<std::function<void(lua_State *)>> _onInited;
};

}
}

#endif
