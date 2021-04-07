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
        void drawText(arc::IDisplayModule* graph, int index, const std::string &name, bool game) const;
        void checkInput(arc::IDisplayModule* graph, arc::DLManager& manager);
    public:
        Interface() = default;
        ~Interface() = default;

        void start(arc::IDisplayModule* graph);
        void update(arc::IDisplayModule* graph, arc::DLManager& manager);

    };
}

extern "C" void *entryPoint();


#endif //INTERFACE
