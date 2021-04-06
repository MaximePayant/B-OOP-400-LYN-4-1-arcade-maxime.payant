/*
** EPITECH PROJECT, 2021
** Interface.cpp
** File description:
** Interface.cpp
*/

#include "../inc/Interface.hpp"
#include "../../../inc/DLManager.hpp"

void Interface::start(arc::IDisplayModule *module)
{
    (void)module;
    m_libIndex = 0;
    m_gameIndex = 0;
    getList();
}

void Interface::drawText(arc::IDisplayModule *module, int index, const std::string &name, bool game) const
{
    arc::Color color = ((game && index == m_gameIndex) || (!game && index == m_libIndex)) ? arc::BLUE : arc::WHITE;
    int xPos = (game) ? 100 : 50;

    module->drawText(name, 50, color, {xPos, 25 + (index * 5)});
}

void Interface::checkInput(arc::IDisplayModule *module)
{
    if (module->getKeyDown(arc::PageDown))
        m_libIndex = (m_libIndex == 0) ? (int)m_lib.size() - 1 : m_libIndex - 1;
    else if (module->getKeyDown(arc::PageUp))
        m_libIndex = (m_libIndex == 0) ? 0 : m_libIndex + 1;
    if (module->getKeyDown(arc::Down))
        m_gameIndex = (m_gameIndex == 0) ? (int)m_game.size() - 1 : m_gameIndex - 1;
    else if (module->getKeyDown(arc::PageUp))
        m_gameIndex = (m_gameIndex == 0) ? 0 : m_gameIndex + 1;
    if (module->getKeyDown(arc::Space))
        arc::DLManager::ChangeGraphicModule(m_lib.at(m_libIndex));
    //if (module->getKeyDown(arc::Enter))
}

void Interface::update(arc::IDisplayModule *module)
{
    int index = 0;

    module->checkEvent();
    module->clearWindow();
    checkInput(module);
    module->drawText(std::string("Interface"), 50, arc::WHITE, {70, 5});
    module->drawText(std::string("Library:"), 50, arc::WHITE, {50, 20});
    for (auto& name : m_lib) {
        drawText(module, index, name, false);
        index++;
    }
    index = 0;
    module->drawText(std::string("Game:"), 50, arc::WHITE, {100, 20});
    for (auto& name : m_game) {
        drawText(module, index, name, true);
        index++;
    }
    module->displayWindow();
}