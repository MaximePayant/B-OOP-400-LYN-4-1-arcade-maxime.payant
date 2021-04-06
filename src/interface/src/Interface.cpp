/*
** EPITECH PROJECT, 2021
** Interface.cpp
** File description:
** Interface.cpp
*/

#include "../inc/Interface.hpp"

void Interface::start(arc::IDisplayModule *module)
{
    (void)module;
    m_libIndex = 0;
    m_gameIndex = 0;
    getList();
}

void Interface::DrawText(arc::IDisplayModule *module, int index, const std::string &name, bool game) const
{
    arc::Color color = ((game && index == m_gameIndex) || (!game && index == m_libIndex)) ? arc::BLUE : arc::WHITE;
    int xPos = (game) ? 100 : 50;

    module->drawText(name, 50, color, {xPos, 25 + (index * 5)});
}

void Interface::update(arc::IDisplayModule *module)
{
    int index = 0;

    module->checkEvent();
    module->clearWindow();
    if (module->getKeyDown(arc::PageDown))
        m_libIndex = (m_libIndex == 0) ? (int)m_lib.size() : m_libIndex - 1;
    module->drawText(std::string("Interface"), 50, arc::WHITE, {70, 5});
    module->drawText(std::string("Library:"), 50, arc::WHITE, {50, 20});
    for (auto& name : m_lib) {
        DrawText(module, index, name, false);
        index++;
    }
    index = 0;
    module->drawText(std::string("Game:"), 50, arc::WHITE, {100, 20});
    for (auto& name : m_game) {
        DrawText(module, index, name, true);
        index++;
    }
    module->displayWindow();
}