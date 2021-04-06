/*
** EPITECH PROJECT, 2021
** DLManager.hpp
** File description:
** DLManager.hpp
*/

#ifndef DLMANAGER
#define DLMANAGER

#include <string>

#include "DLLoader.hpp"

namespace arc
{
    class DLManager
    {
    private:
        static arc::DLLoader m_module;
        static arc::DLLoader m_game;
    public:
        DLManager() = delete;
        ~DLManager() = default;
        static void init(const std::string& path);
        static void ChangeGraphicModule(const std::string module);
        static void ChangeGameModule(const std::string module);
        static arc::DLLoader& getGraphicsModule();
        static arc::DLLoader& getGameModule();
    };
}

#endif //DLMANAGER
