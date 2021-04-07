/*
** EPITECH PROJECT, 2021
** Interface.cpp
** File description:
** Interface.cpp
*/

#include <iostream>
#include "../../../inc/Interface.hpp"

void arc::Interface::start(arc::IDisplayModule* module)
{
    (void)module;
    m_libIndex = 0;
    m_gameIndex = 0;
    getList();
}

void arc::Interface::drawText(arc::IDisplayModule* graph, int index, const std::string &name, bool game) const
{
    arc::Color color = ((game && index == m_gameIndex) || (!game && index == m_libIndex)) ? arc::BLUE : arc::WHITE;
    int xPos = (game) ? 100 : 50;

    graph->drawText(name, 50, color, {xPos, 25 + (index * 5)});
}

static std::string FormatName(const std::string &path)
{
    auto index = path.find_last_of('_');
    auto lastIndex = path.length() - 4;
    std::string result = path.substr(index + 1, lastIndex - index);

    return (result);
}

void arc::Interface::checkInput(arc::IDisplayModule* graph, arc::DLManager& manager)
{
    if (graph->getKeyDown(arc::PageDown))
        m_libIndex = (m_libIndex == 0) ? (int)m_lib.size() - 1 : m_libIndex - 1;
    else if (graph->getKeyDown(arc::PageUp))
        m_libIndex = (m_libIndex == 0) ? 0 : m_libIndex + 1;
    if (graph->getKeyDown(arc::Down))
        m_gameIndex = (m_gameIndex == 0) ? (int)m_game.size() - 1 : m_gameIndex - 1;
    else if (graph->getKeyDown(arc::U))
        m_gameIndex = (m_gameIndex == 0) ? 0 : m_gameIndex + 1;
    if (graph->getKeyDown(arc::Space))
        manager.ChangeGraphicModule(m_lib.at(m_libIndex));
    if (graph->getKeyDown(arc::Enter)) {
        manager.ChangeGameModule(m_game.at(m_gameIndex));
        manager.state = arc::DLManager::GAME;
    }
}

void arc::Interface::update(arc::IDisplayModule* graph, arc::DLManager& manager)
{
    int index = 0;

    graph->checkEvent();
    graph->clearWindow();
    checkInput(graph, manager);
    graph->drawText(std::string("Interface"), 50, arc::WHITE, {70, 5});
    graph->drawText(std::string("Library:"), 50, arc::WHITE, {50, 20});
    for (auto& name : m_lib) {
        drawText(graph, index, FormatName(name), false);
        index++;
    }
    index = 0;
    graph->drawText(std::string("Game:"), 50, arc::WHITE, {100, 20});
    for (auto& name : m_game) {
        drawText(graph, index, FormatName(name), true);
        index++;
    }
    graph->displayWindow();
}
