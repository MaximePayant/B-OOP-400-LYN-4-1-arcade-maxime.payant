/*
** EPITECH PROJECT, 2021
** Interface.hpp
** File description:
** Interface.hpp
*/

#ifndef INTERFACE
#define INTERFACE

#include "IDisplayModule.hpp"
#include "DLLoader.hpp"
#include "DLManager.hpp"
#include "IGame.hpp"
#include <vector>

namespace arc
{
    class Interface
    {
        int m_gameIndex;
        int m_libIndex;
        std::vector<std::string> m_lib;
        std::vector<std::string> m_game;

        void getList();
        void drawText(std::shared_ptr<arc::IDisplayModule>& graph, int index, const std::string &name, bool game) const;
        void checkInput(std::shared_ptr<arc::IDisplayModule>& graph, arc::DLManager& manager);
    public:
        Interface() = default;
        ~Interface() = default;

        void start(std::shared_ptr<arc::IDisplayModule>& graph);
        void update(std::shared_ptr<arc::IDisplayModule>& graph, arc::DLManager& manager);

    };
}

extern "C" void *entryPoint();


#endif //INTERFACE
